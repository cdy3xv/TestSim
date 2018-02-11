/**
 * TestSim
 * Component: sample_sensors.h
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Header File For Model Of Sample Sensor Suite For Use As Sensor In TestSim
 *
 **/

#ifndef TESTSIM_SAMPLE_SENSORS_H
#define TESTSIM_SAMPLE_SENSORS_H

#include "sensor.h"

int gaugeModel(dut_to_sens_t *in_ptr, sens_to_sup_t *out_ptr);

int feedbackModel(dut_to_sens_t *in_ptr, sens_to_sup_t *out_ptr);

#endif /* TESTSIM_SAMPLE_SENSORS_H */
