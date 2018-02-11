/**
 * TestSim
 * Component: steel_1x1_compress.h
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Header File For Steel 1x1" Cross Section Bar In Compression For Use As DUT In TestSim
 *
 **/

#ifndef TESTSIM_STEEL_1X1_COMPRESS_H
#define TESTSIM_STEEL_1X1_COMPRESS_H

#include "dut.h"

// Material Properties
#define YOUNGS_MOD	209		// ASTM-A36 In GPa
#define AREA		0.0006452	// 1 in^2 To m^2

// Conversion Factors
#define GPA_TO_MPA	1000
#define GPA_TO_KPA	1000 * GPA_TO_MPA


#endif /* TESTSIM_STEEL_1X1_COMPRESS_H */
