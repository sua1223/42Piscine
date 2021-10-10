#include <unistd.h>
#include <stdio.h>
#include "ft_putchar.c"

void vertex(int a, int b, int i, int j)
{
  if (a==1 && b==1)
    ft_putchar('/');
  else if (a==1)
  {
    if(i==1)
      ft_putchar('/');
    else
      ft_putchar('\\');
  }
  else if (b==1)
  {
    if(j==1)
      ft_putchar('/');
    else
      ft_putchar('\\');
  }
  else{
    if (i==j || (i==b && j==a))
      ft_putchar('/');
    else
      ft_putchar('\\');
  }
}

int isSquare(int a, int b)
{
  if (a<=0 || b<=0)
    return (0);
  return (1);
}

void rush(int a, int b)
{
  int i;
  int j;
  i=1;
  if (isSquare(a, b))
  {
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
}
