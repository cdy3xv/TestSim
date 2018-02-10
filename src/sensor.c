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
	
	if(initPort(&if_me, SENS_PORT))
		return 1;

	if(pthread_create(&polling_thread, NULL, PollDUT, (void *)&if_me)) {
		perror("Cannot Create Sensor Polling Thread");
		return 1;
	}

	if(initLBAddr(&addr_sup, SUP_PORT))
		return 1;

	while(1) {
		if(udpRecv(&if_me, (void *)&from_dut, sizeof(from_dut)))
			return 1;

		if(udpSend(&if_me, (void *)&to_sup, sizeof(to_sup), &addr_sup))
			return 1;
	}

	return 0;
}

void *PollDUT(void *arg_ptr)
{
	// May Have To Define A Separate Socket For This Thread (On A Different Port?)
	udp_if_t *if_ptr = (udp_if_t *)arg_ptr;
	
	// Payloads
	dut_input_t to_dut;
	poll_t poll;

	struct sockaddr_in addr_dut;

	if(initLBAddr(&addr_dut, DUT_PORT))
		return NULL;

	while(1) {
		/* Do Any Necessary Manipulations To Poll Payload */

		to_dut.poll = poll;
		if(udpSend(if_ptr, (void *)&to_dut, sizeof(to_dut), &addr_dut))
			return NULL;

		nanosleep(&sample_time, NULL);
	}
}
