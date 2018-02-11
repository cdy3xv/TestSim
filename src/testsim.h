/**
 * TestSim
 * Component: testsim.h
 * Author: Connor Young
 *
 * (C) 2018 by Connor Young (connor.young3@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Common Header File For All TestSim Components
 *
 **/

#ifndef TESTSIM_H
#define TESTSIM_H

// Library Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Port Numbers For The Simulation Components
#define SUP_PORT	5428
#define SENS_PORT	5429
#define DUT_PORT	5430
#define ACT_PORT	5431

// Hash To Differentiate Poll From Actuation
#define POLL_HASH	0xFFFF8000 // NaN As A Double Or A Float

// UDP Interface Typedef
typedef struct _udp_if_t {
	int s;
	struct sockaddr_in *addr_ptr;
} udp_if_t;

// Sensor To Supervisor Payload Typdef
typedef struct _sens_to_sup_t {
	double displacement_read;
	double load_read;
} sens_to_sup_t;

// Supervisor To Actuator Payload Typedef
typedef struct _sup_to_act_t {
	double force_cmd;
} sup_to_act_t;

// Actuator To DUT Payload Typedef
typedef struct _act_to_dut_t {
	double force_actual;
} act_to_dut_t;

// Sensor Sample Poll Payload Typedef
typedef struct _poll_t {
	int hash;
} poll_t;

// DUT Input Payload Typedef
typedef union _dut_input_t {
	act_to_dut_t act_to_dut;
	poll_t poll;
} dut_input_t;

// Dut To Sensor Payload Typedef
typedef struct _dut_to_sens_t {
	double displacement_actual;
	double load_actual;
} dut_to_sens_t;

// Initialize Socket And Bind It To port
int initPort(udp_if_t *if_ptr, int port);

// Initialize addr To Loopback On port
int initLBAddr(struct sockaddr_in *addr, int port);

// Blocking Receive From Socket
int udpRecv(udp_if_t *if_ptr, void *buf_ptr, int size);

// Send To dest Over Socket
int udpSend(udp_if_t *if_ptr, void *data, int size, struct sockaddr_in *dest_ptr);

#endif
