/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujang <sujang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:59:22 by sujang            #+#    #+#             */
/*   Updated: 2021/10/12 09:55:12 by sujang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_flag;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	combination(int arr[10], int index, int n, int target)
{
	int	i;

	if (n == 0)
	{
		if (g_flag)
		{
			write(1, ", ", 2);
		}
		i = 0;
		while (i < index)
		{
			ft_putchar(arr[i] + '0');
			i++;
		}
		g_flag = 1;
	}
	else
	{
		if (target <= 9)
		{
			arr[index] = target;
			combination(arr, index + 1, n - 1, target + 1);
			combination(arr, index, n, target + 1);
		}
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	g_flag = 0;
	combination(arr, 0, n, 0);
}
