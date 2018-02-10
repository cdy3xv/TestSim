#include "supervisor.h"

#define BUFLEN 512

int main(int argc, char **argv)
{
	struct sockaddr_in addr_me;
	udp_if_t if_me = { 0, &addr_me };

	char buf[BUFLEN];

	// Initialize My Port
	if(initPort(&if_me, SUP_PORT)) {
		return 1;
	}

	while(1) {
		if(udpRecv(&if_me, buf, sizeof(buf))) {
			return 1;
		}

		printf("Data Received: %s\n", buf);
	}

	return 0;
}
