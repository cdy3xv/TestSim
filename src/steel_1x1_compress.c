/**
 * TestSim
 * Component: steel_1x1_compress.c
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Model Of Steel 1x1 Cross-Section Bar Under Compression For Use As DUT In TestSim
 * Assumes Hooke's Law Applies Across Testing Conditions
 *
 **/

#include "steel_1x1_compress.h"

int dutModel(act_to_dut_t *in_ptr, dut_to_sens_t *out_ptr)
{
	// Pass Through Actuation Force, Respresents Sensor Monitoring Actuator
	out_ptr->force_actual = in_ptr->force_actual;

	// Strain = F / (E * A). 1 kPa = 1 (kN / m^2)
	out_ptr->strain_actual = in_ptr->force_actual / (YOUNGS_MOD * GPA_TO_KPA * AREA);

#ifdef DEBUG_COMPRESS
	printf("actual strain:%10f\tconv:%10f\n", out_ptr->strain_actual, (YOUNGS_MOD * GPA_TO_KPA * AREA));
#endif

	return 0;
}
