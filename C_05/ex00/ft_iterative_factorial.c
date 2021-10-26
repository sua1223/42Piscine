/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujang <sujang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:09:06 by sujang            #+#    #+#             */
/*   Updated: 2021/10/24 17:10:00 by sujang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	answer;

	answer = 1;
	if (nb < 0)
		return (0);
	else
	{
		while (nb > 1)
		{
			answer *= nb;
			nb--;
		}
		return (answer);
	}
}
