#include "sensor.h"

int main(int argc, char **argv)
{
	struct sockaddr_in addr_me, addr_sup;
	udp_if_t if_me = { 0, &addr_me };

	char buf[12] = "Hello World!";

	if(initPort(&if_me, SENS_PORT))
		return 1;

	initLPAddr(&addr_sup, SUP_PORT);

	while(1) {
		printf("Sending Data: %s\n", buf);

		if(udpSend(&if_me, buf, 12, &addr_sup))
			return 1;

		nanosleep(&sample_time, NULL);
	}

	return 0;
}
