#include <unistd.h>
#include <stdio.h>
#include "ft_putchar.c"

void vertex(int i, int j)
{
  if (i==j)
    ft_putchar('/');
  else
    ft_putchar('\\');
}


void rush(int a, int b)
{
  int i;
  int j;
  i=1;
  while (i<=b)
  {
    j=1;
    while (j<=a)
    {
      if (i==1 || i==b || j==1 || j==a) // condition of edge
      {
        if ((i==1 && j==1) || (i==b && j==a) || (i==b && j==1) || (i==1 && j==a)) // print vertex
          vertex(a, b, i , j);
        else
          ft_putchar('*');
      }
      else
        ft_putchar(' ');
      j++;
    }
    ft_putchar('\n');
    i++;
  }
}
