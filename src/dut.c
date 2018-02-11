/**
 * TestSim
 * Component: dut.c
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Function Definitions For DUT Component Of TestSim
 *
 **/

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
#ifdef DEBUG_COMMS
			printf("Received Poll\n");
#endif

			if(udpSend(&if_me, (void *)&to_sens, sizeof(to_sens), &addr_sens))
				return 1;
		}
		else {
			/* Manipulate State Based On Actuation */
			if(dutModel(&(input.act_to_dut), &to_sens))
				return 1;

#ifdef DEBUG_COMMS
			printf("Adjusted To Actuation\n");
#endif
		}
	}

	return 0;
}
