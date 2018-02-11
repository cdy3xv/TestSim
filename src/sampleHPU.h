/**
 * TestSim
 * Component: sampleHPU.h
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Header File For Model Of Sample HPU For Use As Actuator In TestSim
 * Pump Pressure Curve Roughly Based On http://www.hydraproducts.co.uk/portals/0/curve1.png
 * Assumes 0.1 in^2 Pressure Head Applied To 1 in^2 Application Plate (60 bar = 6000 kPa = 600 kN Applied)
 *
 **/

#ifndef TESTSIM_SAMPLEHPU_H
#define TESTSIM_SAMPLEHPU_H

#include "actuator.h"

// Conversion Factors
#define KPA_TO_KN	0.1	// See Assumption In File Description

// Noise Factors
#define INPUT_NOISE	1	// 1 A Noise. This Feels Like A Big Number, But You Never Know	

#define PRESS_CURVE_SIZE 5

typedef struct _curr_to_press_t {
	double current;		// A
	double pressure;	// kPa
} curr_to_press_t;

static const curr_to_press_t pressure_curve[PRESS_CURVE_SIZE] = {
	{ 0,	0	}, // Scales Linearly Down To 0. Not Realistic, But Simplifies Model
	{ 80,	1000	},
	{ 180,	4000	},
	{ 225,	6000	},
	{ 250,	7500	},
};

#endif /* TESTSIM_SAMPLEHPU_H */
