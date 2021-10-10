#include <unistd.h>
#include "ft_putchar.c"
//void ft_putchar(char c);

void vertex(int j)
{
	if(j==1)
		ft_putchar('A');
	else
		ft_putchar('C');
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
    if(isSquare(a,b))
    {
        while (i<=b)
        {
            j=1;
            while (j<=a)
            {
                if (i==1 || i==b || j==1 || j==a)
                {
                    if ((i==1 && j==1) || (i==b && j==a) || (i==b && j==1) || (i==1 && j==a))
                        vertex(j);
                    else
                        ft_putchar('B');
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