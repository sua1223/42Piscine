#include <unistd.h>
void	ft_putchar(char c);

int	isSquare(int a, int b)
{
	if (a <= 0 || b <= 0)
		return (0);
	return (1);
}

void	rush(int a, int b)
{
	int	i;
	int	j;
	i = 1;
	if (isSquare(a, b))
	{
		while (i <= b)
		{
			j = 1;
			while (j <= a)
			{
				if (i == 1 || i == b || j == 1 || j == a)
				{
					if ((j!= 1 && j != a) && (i == 1 || i == b))
						ft_putchar('-');
					else if ((i != 1 && i != b) && (j == 1 || j == a))
						ft_putchar('|');
					else
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
}
