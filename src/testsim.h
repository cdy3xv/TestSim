#ifndef TESTSIM_H
#define TESTSIM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SUP_PORT	5428
#define SENS_PORT	5429
#define DUT_PORT	5430
#define ACT_PORT	5431

typedef struct _udp_if_t {
	int s;
	struct sockaddr_in *addr_ptr;
} udp_if_t;

// Initialize Socket And Bind It To port
int initPort(udp_if_t *if_ptr, int port);

// Initialize addr To Broadcast On port
int initLPAddr(struct sockaddr_in *addr, int port);

// Blocking Receive From Socket
int udpRecv(udp_if_t *if_ptr, void *buf_ptr, int size);

// Send To dest Over Socket
int udpSend(udp_if_t *if_ptr, void *data, int size, struct sockaddr_in *dest_ptr);

#endif
