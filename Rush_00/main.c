#include <unistd.h>
#include <stdio.h>
#include "rush04.c"

int main()
{
  printf("(5,3)\n");
  rush(5,3);
  printf("(5,1)\n");
  rush(5,1);
  printf("(1,5)\n");
  rush(1,5);
  printf("(1,1)\n");
  rush(1,1);
  printf("(4,4)\n");
  rush(4,4);
  printf("(4,0)\n");
  rush(4,0);
  printf("(0,4)\n");
  rush(0,4);
  printf("(0,0)\n");
  rush(0,0);
  printf("(-1,4)\n");
  rush(-1,4);
  return (0);
}
