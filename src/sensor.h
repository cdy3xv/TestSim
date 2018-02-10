#ifndef TESTSIM_SENSOR_H
#define TESTSIM_SENSOR_H

#include <time.h>
#include <pthread.h>

#include "testsim.h"

#define MS_TO_NS 1000000

#define SAMPLE_DT_MS 900

static struct timespec sample_time = { 0, SAMPLE_DT_MS * MS_TO_NS };

// Poll Device Under Test To Simulate Sensor Sampling
void *PollDUT(void *arg_ptr);

#endif /* TESTSIM_SENSOR_H */

