/* vi: set sw=4 ts=4: */
/*
 * arpping.c
 *
 * Mostly stolen from: dhcpcd - DHCP client daemon
 * by Yoichi Hariguchi <yoichi@fore.com>
 */

#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sysinfo.h>
#include <netinet/if_ether.h>
#include <net/if_arp.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "dhcpd.h"
#include "debug.h"
#include "arpping.h"

static long _uptime(void)
{
	struct sysinfo info;
	sysinfo(&info);
	return info.uptime;
}

/* args:	yiaddr - what IP to ping
 *		ip - our ip
 *		mac - our arp address
 *		interface - interface to use
 * retn: 	1 addr free
 *		0 addr used
 *		-1 error 
 */  

int arpping(u_int32_t yiaddr, u_int32_t ip, unsigned char *mac, char *interface)
{
	int	timeout = 2;
	int optval = 1;
	int	s; /* socket */
	int	rv = 1; /* return value */
	struct sockaddr addr; /* for interface name */
	struct arpMsg arp;
	fd_set fdset;
	struct timeval tm;
	long prevTime, nowTime;

	if ((s = socket (PF_PACKET, SOCK_PACKET, htons(ETH_P_ARP))) == -1)
	{
		LOG(LOG_ERR, "Could not open raw socket");
		return -1;
	}

	if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) == -1)
	{
		LOG(LOG_ERR, "Could not setsocketopt on raw socket");
		close(s);
		return -1;
	}

	/* send arp request */
	memset(&arp, 0, sizeof(arp));
	memcpy(arp.ethhdr.h_dest, MAC_BCAST_ADDR, 6);	/* MAC DA */
	memcpy(arp.ethhdr.h_source, mac, 6);		/* MAC SA */
	arp.ethhdr.h_proto = htons(ETH_P_ARP);		/* protocol type (Ethernet) */
	arp.htype = htons(ARPHRD_ETHER);		/* hardware type */
	arp.ptype = htons(ETH_P_IP);			/* protocol type (ARP message) */
	arp.hlen = 6;					/* hardware address length */
	arp.plen = 4;					/* protocol address length */
	arp.operation = htons(ARPOP_REQUEST);		/* ARP op code */
	memcpy(arp.sInaddr, &ip, 4);					/* source IP address */
	memcpy(arp.sHaddr, mac, 6);			/* source hardware address */
	memcpy(arp.tInaddr, &yiaddr, 4);				/* target IP address */

	memset(&addr, 0, sizeof(addr));
	strcpy(addr.sa_data, interface);
	if (sendto(s, &arp, sizeof(arp), 0, &addr, sizeof(addr)) < 0)
		rv = 0;

	/* wait arp reply, and check it */
	tm.tv_usec = 0;
	prevTime = _uptime();
	while (timeout > 0)
	{
		FD_ZERO(&fdset);
		FD_SET(s, &fdset);
		tm.tv_sec = timeout;
		DEBUG(LOG_INFO, "Enter ARPPING select (timeout=%d, pretime=%d) ....\n", (int)timeout, (int)prevTime);
		if (select(s + 1, &fdset, (fd_set *) NULL, (fd_set *) NULL, &tm) < 0)
		{
			DEBUG(LOG_ERR, "Error on ARPING request: %s", strerror(errno));
			if (errno != EINTR) rv = 0;
		}
		else if (FD_ISSET(s, &fdset))
		{
			DEBUG(LOG_INFO, "Receive ARP response ...\n");
			if (recv(s, &arp, sizeof(arp), 0) < 0 ) rv = 0;
			if (arp.operation == htons(ARPOP_REPLY) && 
					bcmp(arp.tHaddr, mac, 6) == 0 && 
					*((u_int *) arp.sInaddr) == yiaddr)
			{
				DEBUG(LOG_INFO, "Valid arp reply receved for this address");
				rv = 0;
				break;
			}
		}
		else
		{
			DEBUG(LOG_INFO, "ARPPING timeout ...\n");
		}
		nowTime = _uptime();
		DEBUG(LOG_INFO, "Update timeout=%d, now=%d, prev=%d >>\n",
				(int)timeout, (int)nowTime, (int)prevTime);
		timeout -= (nowTime - prevTime);
		prevTime = _uptime();
		DEBUG(LOG_INFO, "Update timeout=%d, now=%d, prev=%d <<\n",
				(int)timeout, (int)nowTime, (int)prevTime);
	}
	close(s);
	DEBUG(LOG_INFO, "%salid arp replies for this address", rv ? "No v" : "V");	 
	return rv;
}
