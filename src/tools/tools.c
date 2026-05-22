#include "tools.h"

bool is_valid_ip_addr(char *p_addr, struct in_addr *sa)
{
  if (!(inet_pton(AF_INET, p_addr, sa) != 0)) {
    return false;
  }

  return true;
}

bool is_valid_ip_port(char *ip_port)
{
    if (!(atoi(ip_port) >= 1024 && atoi(ip_port) <= 65535)) {
      return false;
    }
    
    return true;
}

void free_addresses(int count, ...)
{
   va_list list;
   int j = 0;
   int* addr = malloc(0);

   va_start(list , count); 
   for(j=0; j<count; j++)
   {
    addr = va_arg(list, int*);
    free(addr);
    addr = NULL;
   }

   addr = malloc(0);
   va_end(list);
}