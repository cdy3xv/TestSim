#include "dut.h"

int main(int argc, char **argv)
{
	// Networking Variables
	struct sockaddr_in addr_me, addr_sens;
	udp_if_t if_me = { 0, &addr_me };
	
	// Payloads
	dut_input_t input;
	dut_to_sens_t to_sens;

	// Init Networking Variables
	if(initPort(&if_me, DUT_PORT))
		return 1;
	if(initLBAddr(&addr_sens, SENS_PORT))
		return 1;

	while(1) {
		// Wait On Actuation From Actuator
		if(udpRecv(&if_me, (void *)&input, sizeof(input)))
			return 1;

		// If Packet Was A Sensor Poll
		if(input.poll.hash == POLL_HASH) {
			printf("Received Poll\n");
			if(udpSend(&if_me, (void *)&to_sens, sizeof(to_sens), &addr_sens))
				return 1;
		}
		else {
			/* Manipulate State Based On Actuation */
			printf("Adjusted To Actuation\n");
		}
	}

	return 0;
}
