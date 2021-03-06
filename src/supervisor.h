/**
 * TestSim
 * Component: supervisor.h
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Header File For Supervisor Component Of TestSim
 *
 **/

#ifndef TESTSIM_SUPERVISOR_H
#define TESTSIM_SUPERVISOR_H

#include "testsim.h"

int supModel(sens_to_sup_t *in_ptr, sup_to_act_t *out_ptr);

#endif /* TESTSIM_SUPERVISOR_H */

