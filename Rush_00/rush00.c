#include <unistd.h>
#include "ft_putchar.c"

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
        if ((j!=1 && j!=a) && (i==1 || i==b)) // print width
          ft_putchar('-');
        else if ((i!=1 && i!=b) && (j==1 || j==a)) // print height
          ft_putchar('|');
        else // print vertex
          ft_putchar('o');
      }
      else
        ft_putchar(' ');
      j++;
    }
    ft_putchar('\n');
    i++;
  }
}
