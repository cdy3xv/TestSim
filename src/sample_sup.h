/**
 * TestSim
 * Component: sample_sup.h
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Header File For Model Of Sample Supervisor For Use As Supervisor In TestSim
 *
 **/

#ifndef TESTSIM_SAMPLE_SUP_H
#define TESTSIM_SAMPLE_SUP_H

#include "supervisor.h"

// PID Coefficients
#define P		30000
#define I		70000
#define D		0

// Test Routine Parameters
#define TIME_STEP	200	// Expressed In Units Of Sensor Samples
#define STRAIN_STEP	0.0001
#define MAX_STRAIN	0.01
#define MIN_STRAIN	0

#endif
