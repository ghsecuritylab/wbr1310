#!/bin/sh
echo [$0] ... > /dev/console
TROOT=`rgdb -i -g /runtime/template_root`
[ "$TROOT" = "" ] && TROOT="/etc/templates"
case "$1" in
password)
	rgdb -A $TROOT/httpd/httpasswd.php > /var/etc/httpasswd
	;;
start|restart)
	[ -f /var/run/webs_stop.sh ] && sh /var/run/webs_stop.sh > /dev/console
	rgdb -A $TROOT/httpd/webs_run.php -V generate_start=1 > /var/run/webs_start.sh
	rgdb -A $TROOT/httpd/webs_run.php -V generate_start=0 > /var/run/webs_stop.sh
	sh /var/run/webs_start.sh > /dev/console
	;;
stop)
	if [ -f /var/run/webs_stop.sh ]; then
		sh /var/run/webs_stop.sh > /dev/console
		rm -f /var/run/webs_stop.sh
	fi
	;;
*)
	echo "usage: $0 {start|stop|restart|password}"
	;;
esac
