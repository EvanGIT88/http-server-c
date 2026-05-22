#ifndef VALIDATORS_H_   /* Include guard */
#define VALIDATORS_H_

#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdbool.h>
#include <stdarg.h>

bool is_valid_ip_addr(char *p_addr, struct in_addr *sa);
bool is_valid_ip_port(char *ip_port);
void free_addresses(int count, ...);

#endif