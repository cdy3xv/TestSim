/**
 * TestSim
 * Component: sampleHPU.c
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Model Of Sample HPU For Use As Actuator In TestSim
 *
 **/

#include "sampleHPU.h"

int actModel(sup_to_act_t *in_ptr, act_to_dut_t *out_ptr)
{
	// Calculate Noise.
	// Ideally This Would Be Gaussian, But Constant Will Do For A Simple Model
	double current_noise = (rand() % 100000) / (100000 / INPUT_NOISE);

	// Calculate Actual Current Received
	double current_actual = in_ptr->current_cmd + current_noise;
	if (current_actual < 0)
		current_actual = 0;

	// Translate To Pressure
	double pressure = -1;
	int i;
	for(i = 0; i < PRESS_CURVE_SIZE; i++) {
		if(current_actual < pressure_curve[i].current) {
			/* Linearly Approximate Pressure Based On Curve Points */
			double current1 = pressure_curve[i].current;
			double current0 = pressure_curve[i - 1].current;
			double current_diff = current1 - current0;

			double press1 = pressure_curve[i].pressure;
			double press0 = pressure_curve[i - 1].pressure;
			double press_diff = press1 - press0;

			double current_pct = (current_actual - current0) / current_diff;
			pressure = press0 + press_diff * current_pct;

			// Pressure Calculated, No Need To Continue
			break;
		}
	}
	if(pressure == -1)
	{
		printf("Error: Overcurrent on Actuator!\n");
		return 1;
	}

	// Translate to Force
	out_ptr->force_actual = pressure * KPA_TO_KN;

	return 0;
}
