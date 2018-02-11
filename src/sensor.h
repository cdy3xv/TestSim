/**
 * TestSim
 * Component: sensor.h
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Header File For Sensor Component Of TestSim
 *
 **/

#ifndef TESTSIM_SENSOR_H
#define TESTSIM_SENSOR_H

#include <time.h>
#include <pthread.h>

#include "testsim.h"

#define MS_TO_NS 1000000

#define SAMPLE_DT_MS 100

static struct timespec sample_time = { 0, SAMPLE_DT_MS * MS_TO_NS };

// Poll Device Under Test To Simulate Sensor Sampling
void *PollDUT(void *arg_ptr);

// Sensor Model
int sensorModel(dut_to_sens_t *in_ptr, sens_to_sup_t *out_ptr);

#endif /* TESTSIM_SENSOR_H */

