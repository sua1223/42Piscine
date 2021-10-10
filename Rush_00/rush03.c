/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujang <sujang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:52:12 by sujang            #+#    #+#             */
/*   Updated: 2021/10/10 14:52:24 by sujang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c);

void	vertex(int j)
{
	if (j == 1)
		ft_putchar('A');
	else
		ft_putchar('C');
}

int	isSquare(int a, int b)
{
	if (a <= 0 || b <= 0)
		return (0);
	return (1);
}

void	print_square(int a, int b, int i, int j)
{
	if (i == 1 || i == b || j == 1 || j == a)
	{
		if ((i == 1 && j == 1) || (i == b && j == a))
			vertex(j);
		else if ((i == b && j == 1) || (i == 1 && j == a))
			vertex(j);
		else
			ft_putchar('B');
	}
	else
		ft_putchar(' ');
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
				print_square(a, b, i, j);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}
