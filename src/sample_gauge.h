/**
 * TestSim
 * Component: sample_gauge.h
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Header File For Model Of Sample Strain Gauge For Use As Part Of Sensor In TestSim
 * Assumes Temperature Compensation of 2 ppm/deg C
 * Assumes Operating Environment of +/- <5 C From Ref Temperature
 * Assumes GF Tolerance of +/- 1% Within Package
 * Assumes Full Wheatstone Bridge Configuration
 *
 **/

#ifndef TESTSIM_SAMPLE_GAUGE_H
#define TESTSIM_SAMPLE_GAUGE_H

#include "sample_sensors.h"

// Noise Factors
#define TEMP_NOISE	0.00001	// See Assumptions In Header
#define GF_TOLERANCE	0.01	// See Assumptions In Header
#define TRANS_NOISE	0.001	// 1 mV Transmission Noise

// Material Properties
#define POISSONS RATIO	0.3	// In Reality This Is A Property Of The DUT, But It Is Defined Here For Simplicity

#endif /* TESTSIM_SAMPLE_GAUGE_H */
