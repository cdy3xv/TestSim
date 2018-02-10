#include "testsim.h"

int initPort(udp_if_t *if_ptr, int port)
{
	// Open Socket
	if((if_ptr->s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
		perror("Unable to open socket");
		return 1;
	}

	// Enable Broadcasting
	int enabled = 1;
	if(setsockopt(if_ptr->s, SOL_SOCKET, SO_BROADCAST, &enabled, sizeof(enabled))) {
		perror("Unable to assign broadcast permission");
		return 1;
	}

	// Initialize Empty Socket Address
	memset((char *)if_ptr->addr_ptr, 0, sizeof(struct sockaddr_in));

	// Fill In Socket Address With Port Parameters
	if_ptr->addr_ptr->sin_family = AF_INET;
	if_ptr->addr_ptr->sin_port = htons(port);
	 if_ptr->addr_ptr->sin_addr.s_addr = htonl(INADDR_ANY);
	// if_ptr->addr_ptr->sin_addr.s_addr = inet_addr("127.255.255.2");

	// Bind Socket To Port
	if(bind(if_ptr->s, (struct sockaddr *)if_ptr->addr_ptr, sizeof(struct sockaddr_in))) {
		perror("Unable to bind socket to port");
		return 1;
	}

	return 0;
}

int initLBAddr(struct sockaddr_in *addr, int port)
{
	// Initialize Empty Socket Address
	memset((char *)addr, 0, sizeof(struct sockaddr_in));

	// Set Port Parameters
	addr->sin_family = AF_INET;
	addr->sin_port = htons(port);
	
	// Set Broadcast Address Parameter
	if(!inet_aton("127.0.0.1", &(addr->sin_addr))) {
		perror("Unable to assign broadcast address");
		return 1;
	}

	return 0;
}

int udpRecv(udp_if_t *if_ptr, void *buf_ptr, int size)
{
	int recv_len;
	struct sockaddr_in sender;
	unsigned int slen = sizeof(sender);

	if((recv_len = recvfrom(if_ptr->s, (char *)buf_ptr, size, 0, (struct sockaddr *)&sender, &slen)) < 0) {
		perror("Error receiving packet");
		return 1;
	}

	return 0;
}

int udpSend(udp_if_t *if_ptr, void *data, int size, struct sockaddr_in *dest_ptr)
{
	unsigned int slen = sizeof(*dest_ptr);

	if(sendto(if_ptr->s, (char *)data, size, 0, (struct sockaddr *)dest_ptr, slen) < 0) {
		perror("Error sending packet");
		return 1;
	}

	return 0;
}
