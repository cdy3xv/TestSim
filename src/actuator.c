/**
 * TestSim
 * Component: actuator.c
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Function Definitions For Actuator Component Of TestSim
 *
 **/

#include "actuator.h"

int main(int argc, char **argv)
{
	// Networking Variables
	struct sockaddr_in addr_me, addr_dut;
	udp_if_t if_me = { 0, &addr_me };
	
	// Payloads
	sup_to_act_t from_sup;
	act_to_dut_t act_to_dut;
	dut_input_t to_dut;

	// Init Networking Variables
	if(initPort(&if_me, ACT_PORT))
		return 1;
	if(initLBAddr(&addr_dut, DUT_PORT))
		return 1;

	while(1) {
		// Wait For Packet From Supervisor With Instructions
		if(udpRecv(&if_me, (void *)&from_sup, sizeof(from_sup)))
			return 1;

		/* Actuator Model */
		printf("Actuation Applied\n");

		// Apply Actuation To DUT
		to_dut.act_to_dut = act_to_dut;
		if(udpSend(&if_me, (void *)&to_dut, sizeof(to_dut), &addr_dut))
			return 1;
	}

	return 0;
}
