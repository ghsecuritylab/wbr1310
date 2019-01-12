/*
 * Automatically generated header file: don't edit
 */

#define AUTOCONF_INCLUDED

/* Version Number */
#define BB_VER "(null)"
#define BB_BT "(null)"

#define BR2_HAVE_DOT_CONFIG 1
#undef BR2_alpha
#undef BR2_arm
#undef BR2_armeb
#undef BR2_cris
#undef BR2_i386
#undef BR2_m68k
#define BR2_mips 1
#undef BR2_mipsel
#undef BR2_nios2
#undef BR2_powerpc
#undef BR2_sh
#undef BR2_sparc
#undef BR2_x86_64
#define BR2_ARCH "mips"
#define BR2_ENDIAN "BIG"

/*
 * Build options
 */
#define BR2_WGET "wget --passive-ftp"
#define BR2_SVN "Subversion (svn) checkout command"
#define BR2_TAR_OPTIONS ""
#define BR2_DL_DIR "$(BASE_DIR)/dl"
#define BR2_SOURCEFORGE_MIRROR "easynews"
#define BR2_STAGING_DIR "$(BUILD_DIR)/staging_dir"
#define BR2_TOPDIR_PREFIX ""
#define BR2_TOPDIR_SUFFIX ""
#define BR2_GNU_BUILD_SUFFIX "pc-linux-gnu"
#define BR2_GNU_TARGET_SUFFIX "linux-uclibc"
#define BR2_JLEVEL 1

/*
 * Toolchain Options
 */

/*
 * Kernel Header Options
 */
#define BR2_KERNEL_HEADERS_2_4_25 1
#undef BR2_KERNEL_HEADERS_2_4_27
#undef BR2_KERNEL_HEADERS_2_4_29
#undef BR2_KERNEL_HEADERS_2_4_31
#undef BR2_KERNEL_HEADERS_2_6_9
#undef BR2_KERNEL_HEADERS_2_6_11
#undef BR2_KERNEL_HEADERS_2_6_12
#define BR2_DEFAULT_KERNEL_HEADERS "2.4.25"

/*
 * uClibc Options
 */
#undef BR2_UCLIBC_VERSION_SNAPSHOT
#undef BR2_ENABLE_LOCALE
#undef BR2_PTHREADS_NONE
#undef BR2_PTHREADS
#define BR2_PTHREADS_OLD 1
#undef BR2_PTHREADS_NATIVE

/*
 * Binutils Options
 */
#define BR2_BINUTILS_VERSION_2_14_90_0_8 1
#undef BR2_BINUTILS_VERSION_2_15
#undef BR2_BINUTILS_VERSION_2_15_94_0_2_2
#undef BR2_BINUTILS_VERSION_2_15_97
#undef BR2_BINUTILS_VERSION_2_16_1
#undef BR2_BINUTILS_VERSION_2_16_90_0_3
#undef BR2_BINUTILS_VERSION_2_16_91_0_5
#undef BR2_BINUTILS_VERSION_2_16_91_0_6
#undef BR2_BINUTILS_VERSION_2_16_91_0_7
#undef BR2_BINUTILS_VERSION_2_16_93
#undef BR2_BINUTILS_VERSION_2_16_94
#undef BR2_BINUTILS_VERSION_2_17
#undef BR2_BINUTILS_VERSION_2_17_50_0_2
#define BR2_BINUTILS_VERSION "2.14.90.0.8"
#define BR2_EXTRA_BINUTILS_CONFIG_OPTIONS ""

/*
 * Gcc Options
 */
#define BR2_GCC_VERSION_3_3_5 1
#undef BR2_GCC_VERSION_3_3_6
#undef BR2_GCC_VERSION_3_4_2
#undef BR2_GCC_VERSION_3_4_3
#undef BR2_GCC_VERSION_3_4_4
#undef BR2_GCC_VERSION_3_4_5
#undef BR2_GCC_VERSION_3_4_6
#undef BR2_GCC_VERSION_4_0_0
#undef BR2_GCC_VERSION_4_0_1
#undef BR2_GCC_VERSION_4_0_2
#undef BR2_GCC_VERSION_4_0_3
#undef BR2_GCC_VERSION_4_1_0
#undef BR2_GCC_VERSION_4_1_1
#undef BR2_GCC_VERSION_4_2
#undef BR2_GCC_IS_SNAP
#define BR2_GCC_VERSION "3.3.5"
#undef BR2_GCC_USE_SJLJ_EXCEPTIONS
#define BR2_EXTRA_GCC_CONFIG_OPTIONS ""
#define BR2_INSTALL_LIBSTDCPP 1
#undef BR2_INSTALL_LIBGCJ
#undef BR2_INSTALL_OBJC

/*
 * Ccache Options
 */
#undef BR2_CCACHE

/*
 * Gdb Options
 */
#undef BR2_PACKAGE_GDB
#undef BR2_PACKAGE_GDB_SERVER
#undef BR2_PACKAGE_GDB_HOST

/*
 * elf2flt
 */
#undef BR2_ELF2FLT

/*
 * Common Toolchain Options
 */
#undef BR2_PACKAGE_SSTRIP_TARGET
#undef BR2_PACKAGE_SSTRIP_HOST
#define BR2_ENABLE_MULTILIB 1
#define BR2_LARGEFILE 1
#undef BR2_SOFT_FLOAT
#define BR2_TARGET_OPTIMIZATION "-Os -pipe"
#define BR2_CROSS_TOOLCHAIN_TARGET_UTILS 1

/*
 * Package Selection for the target
 */

/*
 * The default minimal system
 */
#undef BR2_PACKAGE_BUSYBOX

/*
 * The minimum needed to build a uClibc development system
 */
#undef BR2_PACKAGE_BASH
#undef BR2_PACKAGE_BZIP2
#undef BR2_PACKAGE_COREUTILS
#undef BR2_PACKAGE_DIFFUTILS
#undef BR2_PACKAGE_ED
#undef BR2_PACKAGE_FINDUTILS
#undef BR2_PACKAGE_FLEX
#undef BR2_PACKAGE_GAWK
#undef BR2_PACKAGE_GCC_TARGET
#undef BR2_PACKAGE_CCACHE_TARGET
#undef BR2_PACKAGE_GREP
#undef BR2_PACKAGE_MAKE
#undef BR2_PACKAGE_PATCH
#undef BR2_PACKAGE_SED
#undef BR2_PACKAGE_TAR

/*
 * Other stuff
 */
#undef BR2_PACKAGE_ACPID
#undef BR2_PACKAGE_ASTERISK
#undef BR2_PACKAGE_AT
#undef BR2_PACKAGE_AUTOCONF
#undef BR2_PACKAGE_AUTOMAKE
#undef BR2_PACKAGE_BERKELEYDB
#undef BR2_PACKAGE_BIND
#undef BR2_PACKAGE_BISON
#undef BR2_PACKAGE_BOA
#undef BR2_PACKAGE_BRIDGE
#undef BR2_PACKAGE_CUSTOMIZE
#undef BR2_PACKAGE_ISC_DHCP
#undef BR2_PACKAGE_DIALOG
#undef BR2_PACKAGE_DIRECTFB
#undef BR2_PACKAGE_DISTCC
#undef BR2_PACKAGE_DM
#undef BR2_PACKAGE_DNSMASQ
#undef BR2_PACKAGE_DROPBEAR
#undef BR2_PACKAGE_ETHTOOL
#undef BR2_PACKAGE_EXPAT
#undef BR2_PACKAGE_E2FSPROGS
#undef BR2_PACKAGE_FAKEROOT
#undef BR2_PACKAGE_FILE
#undef BR2_PACKAGE_FREETYPE
#undef BR2_PACKAGE_GETTEXT
#undef BR2_PACKAGE_LIBINTL
#undef BR2_PACKAGE_GZIP
#undef BR2_PACKAGE_HASERL
#define BR2_PACKAGE_HDPARM 1
#undef BR2_PACKAGE_HOSTAP
#undef BR2_PACKAGE_HOTPLUG
#undef BR2_PACKAGE_IOSTAT
#undef BR2_PACKAGE_IPROUTE2
#undef BR2_PACKAGE_IPSEC_TOOLS
#undef BR2_PACKAGE_IPTABLES
#undef BR2_PACKAGE_JPEG
#undef BR2_PACKAGE_LESS
#undef BR2_PACKAGE_LIBCGI
#undef BR2_PACKAGE_LIBCGICC
#undef BR2_PACKAGE_LIBELF
#undef BR2_PACKAGE_LIBFLOAT
#undef BR2_PACKAGE_LIBGLIB12
#undef BR2_PACKAGE_LIBMAD
#undef BR2_PACKAGE_LIBPCAP
#undef BR2_PACKAGE_LIBPNG
#undef BR2_PACKAGE_LIBSYSFS
#undef BR2_PACKAGE_LIBTOOL
#undef BR2_PACKAGE_LIBUSB
#undef BR2_PACKAGE_LIGHTTPD
#undef BR2_PACKAGE_LINKS
#undef BR2_PACKAGE_LRZSZ
#undef BR2_PACKAGE_LSOF
#undef BR2_PACKAGE_LTP-TESTSUITE
#undef BR2_PACKAGE_LTT
#undef BR2_PACKAGE_LVM2
#undef BR2_PACKAGE_LZO
#undef BR2_PACKAGE_M4
#undef BR2_PACKAGE_MDADM
#undef BR2_PACKAGE_MEMTESTER
#undef BR2_PACKAGE_MICROCOM
#undef BR2_PACKAGE_MICROPERL
#undef BR2_PACKAGE_MICROWIN
#undef BR2_PACKAGE_MKDOSFS
#undef BR2_PACKAGE_MODULE_INIT_TOOLS
#undef BR2_PACKAGE_MODUTILS
#undef BR2_PACKAGE_MPG123
#undef BR2_PACKAGE_MROUTED
#undef BR2_PACKAGE_MTD
#undef BR2_PACKAGE_NANO
#undef BR2_PACKAGE_NCURSES
#undef BR2_PACKAGE_NETKITBASE
#undef BR2_PACKAGE_NETKITTELNET
#undef BR2_PACKAGE_NETSNMP
#undef BR2_PACKAGE_NEWT
#undef BR2_PACKAGE_NTP
#undef BR2_PACKAGE_OPENNTPD
#undef BR2_PACKAGE_OPENSSH
#undef BR2_PACKAGE_OPENSSL
#undef BR2_PACKAGE_OPENVPN
#undef BR2_PACKAGE_PCIUTILS
#undef BR2_PACKAGE_PORTAGE
#undef BR2_PACKAGE_PORTMAP
#undef BR2_PACKAGE_PPPD
#undef BR2_PACKAGE_PROCPS
#undef BR2_PACKAGE_PSMISC
#undef BR2_PACKAGE_PYTHON
#undef BR2_PACKAGE_QTE
#define BR2_QTE_TMAKE_VERSION "1.13"
#undef BR2_PACKAGE_RAIDTOOLS
#undef BR2_READLINE
#undef BR2_PACKAGE_RSYNC
#undef BR2_PACKAGE_RUBY
#undef BR2_PACKAGE_RXVT
#undef BR2_PACKAGE_SDL
#undef BR2_PACKAGE_SFDISK
#undef BR2_PACKAGE_SLANG
#undef BR2_PACKAGE_SMARTMONTOOLS
#undef BR2_PACKAGE_SOCAT
#undef BR2_PACKAGE_STRACE
#define BR2_PACKAGE_SUDO 1
#undef BR2_PACKAGE_SYSKLOGD
#undef BR2_PACKAGE_SYSVINIT
#undef BR2_PACKAGE_TCL
#undef BR2_PACKAGE_TCPDUMP
#undef BR2_PACKAGE_TFTPD
#undef BR2_PACKAGE_THTTPD
#undef BR2_PACKAGE_TINYLOGIN
#undef BR2_PACKAGE_TINYX
#undef BR2_PACKAGE_TN5250
#undef BR2_PACKAGE_TTCP
#undef BR2_PACKAGE_UDEV
#undef BR2_PACKAGE_UDHCP
#undef BR2_PACKAGE_UEMACS
#undef BR2_PACKAGE_USBUTILS
#undef BR2_PACKAGE_UTIL-LINUX
#undef BR2_PACKAGE_VALGRIND
#undef BR2_PACKAGE_VTUN
#undef BR2_PACKAGE_WGET
#undef BR2_PACKAGE_WHICH
#undef BR2_PACKAGE_WIPE
#undef BR2_PACKAGE_WIRELESS_TOOLS
#undef BR2_PACKAGE_XFSPROGS
#undef BR2_PACKAGE_XORG
#undef BR2_PACKAGE_ZLIB

/*
 * Target Options
 */

/*
 * filesystem for target device
 */
#undef BR2_TARGET_ROOTFS_CRAMFS
#undef BR2_TARGET_ROOTFS_CLOOP
#undef BR2_TARGET_ROOTFS_EXT2
#undef BR2_TARGET_ROOTFS_JFFS2
#undef BR2_TARGET_ROOTFS_SQUASHFS
#undef BR2_TARGET_ROOTFS_TAR

/*
 * bootloader for target device
 */

/*
 * Board Support Options
 */

/*
 * AMD Specific Device Support
 */
#undef BR2_TARGET_AMD_ALCHEMY

/*
 * Generic System Support
 */
#undef BR2_TARGET_GENERIC_ACCESS_POINT
#undef BR2_TARGET_GENERIC_FIREWALL
#undef BR2_TARGET_GENERIC_DEV_SYSTEM
