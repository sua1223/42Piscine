/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujang <sujang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:11:52 by sujang            #+#    #+#             */
/*   Updated: 2021/10/24 17:12:47 by sujang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	answer;

	answer = 1;
	if (power < 0)
		return (0);
	else
	{
		while (power > 0)
		{
			answer *= nb;
			power --;
		}
		return (answer);
	}
}
