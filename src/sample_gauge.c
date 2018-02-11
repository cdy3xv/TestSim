/**
 * TestSim
 * Component: sample_gauge.c
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
 * 1.3 Multiplicator Comes From Bridge Factor of 2.6, Nominal Gauge Factor of 2
 *
 **/

#include "sample_gauge.h"

int gaugeModel(dut_to_sens_t *in_ptr, sens_to_sup_t *out_ptr)
{
	// Convert To Vo/V
	double Vo_V = 1.3 * in_ptr->strain_actual;

	// Add Noise
	Vo_V *= 1 + TEMP_NOISE;
	Vo_V *= 1 + GF_TOLERANCE;
#ifdef DEBUG_GAUGE
	printf("_V:%10f\t",Vo_V);
#endif
	Vo_V += (rand() % 1000) / (1000 / TRANS_NOISE) - (TRANS_NOISE / 2);

	// Convert Back To Strain
	out_ptr->strain_read = Vo_V / 1.3;

#ifdef DEBUG_GAUGE
	printf("V:%10f\tstrain read:%10f\n", Vo_V, out_ptr->strain_read);
#endif

	return 0;
}
