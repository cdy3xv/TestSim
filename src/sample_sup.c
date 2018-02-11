/**
 * TestSim
 * Component: sample_sup.c
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Model Of Sample Supervisor For Use As Supervisor In TestSim
 *
 **/

#include "sample_sup.h"

int supModel(sens_to_sup_t *in_ptr, sup_to_act_t *out_ptr)
{
	// Static Variables
	static double prev_p = 0;
	static double desired_strain = MIN_STRAIN;
	static double pid_i = 0;
	static int ctr = 0, dir = 0;

	// PID Control
	double pid_p = (desired_strain - in_ptr->strain_read);
	pid_i += pid_p * I;
	double pid_d = (pid_p - prev_p) * D;
	prev_p = pid_p;
	pid_p *= P;
	out_ptr->current_cmd = pid_p + pid_i + pid_d;
	if(out_ptr->current_cmd < 0)
		out_ptr->current_cmd = 0;

#ifdef DEBUG_PID
	printf("level:%10f\tp:%10f\ti:%10f\td:%10f\n", desired_strain, pid_p, pid_i, pid_d);
#endif

	// Test Routine
	ctr++;
	if(ctr == TIME_STEP) {
		// Reset Counter
		ctr = 0;

		// Increment Or Decrement Strain
		if(dir == 0)
			desired_strain += STRAIN_STEP;
		else
			desired_strain -= STRAIN_STEP;

		// Change Direction If We Have Reached Test Maximum Or Test Minimum
		if(desired_strain >= MAX_STRAIN)
			dir = 1;
		else if(desired_strain <= MIN_STRAIN)
			dir = 0;
	}

	return 0;
}
