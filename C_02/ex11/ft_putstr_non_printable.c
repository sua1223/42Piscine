/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujang <sujang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:19:41 by sujang            #+#    #+#             */
/*   Updated: 2021/10/14 14:27:53 by sujang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	 int	minus;

	hex = "0123456789abcdef";
	while (*str)
	{
		if (*str <= 31 || *str >= 127)
		{
			write(1, "\\", 1);
			if (*str < 0)
			{
				minus = (-128 - (*str)) * -1 + 128;
				write(1, &hex[minus / 16], 1);
				write(1, &hex[minus % 16], 1);
			}
			else
			{
				write(1, &hex[*str / 16], 1);
				write(1, &hex[*str % 16], 1);
			}
		}
		else
			write(1, str, 1);
		str++;
	}
}
