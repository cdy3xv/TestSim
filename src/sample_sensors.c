/**
 * TestSim
 * Component: sample_sensors.c
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Model Of Sample Sensor Suite For Use As Sensor In TestSim
 *
 **/

#include "sample_sensors.h"

int sensorModel(dut_to_sens_t *in_ptr, sens_to_sup_t *out_ptr)
{
	if(gaugeModel(in_ptr, out_ptr))
		return 1;

	if(feedbackModel(in_ptr, out_ptr))
		return 1;

	return 0;
}
