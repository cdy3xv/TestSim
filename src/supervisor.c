#include "supervisor.h"

int main(int argc, char **argv)
{
	// Networking Variables
	struct sockaddr_in addr_me, addr_act;
	udp_if_t if_me = { 0, &addr_me };

	// Payloads
	sens_to_sup_t from_sens;
	sup_to_act_t to_act;

	// Initialize My Port
	if(initPort(&if_me, SUP_PORT))
		return 1;

	if(initLBAddr(&addr_act, ACT_PORT))
		return 1;

	while(1) {
		if(udpRecv(&if_me, (void *)&from_sens, sizeof(from_sens)))
			return 1;

		/* Make Decisions Based On Sensor Data Here */

		if(udpSend(&if_me, (void *)&to_act, sizeof(to_act), &addr_act))
			return 1;
	}

	return 0;
}
