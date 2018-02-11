/**
 * TestSim
 * Component: sensor.c
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Function Definitions For Sensor Component Of TestSim
 *
 **/

#include "sensor.h"

int main(int argc, char **argv)
{
	// Networking Variables
	struct sockaddr_in addr_me, addr_sup;
	udp_if_t if_me = { 0, &addr_me };

	// Payloads
	dut_to_sens_t from_dut;
	sens_to_sup_t to_sup;

	// Threads
	pthread_t polling_thread;
	
	// Initialize Network Variables
	if(initPort(&if_me, SENS_PORT))
		return 1;
	if(initLBAddr(&addr_sup, SUP_PORT))
		return 1;

	// Start Thread To Time Sensor Readings
	if(pthread_create(&polling_thread, NULL, PollDUT, (void *)&if_me)) {
		perror("Cannot Create Sensor Polling Thread");
		return 1;
	}

	while(1) {
		// Wait For Sensor Poll Response
		if(udpRecv(&if_me, (void *)&from_dut, sizeof(from_dut)))
			return 1;

		/* Sensor Model (Noise, etc) Here */
		if(sensorModel(&from_dut, &to_sup))
			return 1;

#ifdef DEBUG_COMMS
		printf("Sensor Reading\n");
#endif

		// Send Sensor Reading To Supervisor
		if(udpSend(&if_me, (void *)&to_sup, sizeof(to_sup), &addr_sup))
			return 1;
	}

	return 0;
}

void *PollDUT(void *arg_ptr)
{
	// May Have To Define A Separate Socket For This Thread (On A Different Port?)
	// Networking Variables
	udp_if_t *if_ptr = (udp_if_t *)arg_ptr;
	struct sockaddr_in addr_dut;
	
	// Payloads
	dut_input_t to_dut;
	poll_t poll;

	// Initialize Neworking Variables
	if(initLBAddr(&addr_dut, DUT_PORT))
		return NULL;

	while(1) {
		// Do Any Necessary Manipulations To Poll Payload
		poll.hash = POLL_HASH;

#ifdef DEBUG_COMMS
		printf("Polling Sensor\n");
#endif

		// Send Poll To DUT
		to_dut.poll = poll;
		if(udpSend(if_ptr, (void *)&to_dut, sizeof(to_dut), &addr_dut))
			return NULL;

		// Wait Until Next Poll
		nanosleep(&sample_time, NULL);
	}
}
