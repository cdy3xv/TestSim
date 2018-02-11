/**
 * TestSim
 * Component: supervisor.c
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Function Definitions For Supervisor Component Of TestSim
 *
 **/

#include "supervisor.h"

int main(int argc, char **argv)
{
	// Networking Variables
	struct sockaddr_in addr_me, addr_act;
	udp_if_t if_me = { 0, &addr_me };

	// Payloads
	sens_to_sup_t from_sens;
	sup_to_act_t to_act;

	// Initialize Networking Variables
	if(initPort(&if_me, SUP_PORT))
		return 1;
	if(initLBAddr(&addr_act, ACT_PORT))
		return 1;

	while(1) {
		// Wait For Sensor Reading
		if(udpRecv(&if_me, (void *)&from_sens, sizeof(from_sens)))
			return 1;

		/* Make Decisions Based On Sensor Data Here */
		if(supModel(&from_sens, &to_act))
			return 1;

#ifdef DEBUG_COMMS
		printf("Actuation Commanded\n");
#endif

		// Send Actuation Command
		if(udpSend(&if_me, (void *)&to_act, sizeof(to_act), &addr_act))
			return 1;
	}

	return 0;
}
