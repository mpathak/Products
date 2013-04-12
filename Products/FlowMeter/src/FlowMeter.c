#include "stdafx.h"

#ifndef WIN32
#include <endian.h>
#else
#include <winsock2.h>
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN 1234
#define BIG_ENDIAN 4321
#define BYTE_ORDER LITTLE_ENDIAN 
#endif
#endif

#define ETHER_MAC_ADDRESS_LEN 6
struct PSEtherHeader
{
	unsigned char destinationMACAddr[ETHER_MAC_ADDRESS_LEN];
	unsigned char sourceMACAddr[ETHER_MAC_ADDRESS_LEN];
	unsigned short etherType;
};

struct PSIpv4
{
#if BYTE_ORDER == LITTLE_ENDIAN 
	unsigned char	ipv4_hl:4,			/* header length */
					ipv4_v:4;			/* version */
#endif
#if BYTE_ORDER == BIG_ENDIAN			///For Spark system BYTE_ORDER is BIG_ENDIAN
	unsigned char	ipv4_v:4,			/* version */
					ipv4_hl:4;			/* header length */
#endif
	unsigned char	ipv4_tos;			/* type of service */
	unsigned short	ipv4_len;					/* total length */
	unsigned short	ipv4_id;			/* identification */
	unsigned short	ipv4_off;					/* fragment offset field */
#define	IP_DF 0x4000					/* don't fragment flag */
#define	IP_MF 0x2000					/* more fragments flag */
#define	IP_OFFMASK 0x1fff				/* mask for fragmenting bits */
	unsigned char	ipv4_ttl;			/* time to live */
	unsigned char	ipv4_protocol;		/* protocol */
	unsigned short	ipv4_sum;			/* checksum */
	unsigned int ipv4_src,ipv4_dst;	/* source and destination address */
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}