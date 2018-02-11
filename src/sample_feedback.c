/**
 * TestSim
 * Component: sample_feedback.c
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Model Of Sample Feedback Sensor For Use As Part Of Sensor In TestSim
 *
 **/

#include "sample_feedback.h"

int feedbackModel(dut_to_sens_t *in_ptr, sens_to_sup_t *out_ptr)
{
	double noise = (rand() % 100000) / (100000 * NOISE_AMP) - (NOISE_AMP / 2);
	out_ptr->force_read = in_ptr->force_actual + noise;

	return 0;
}
