/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:36:59 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 13:37:00 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"rush02.h"

int	ft_fill_2num_map(void)
{
	int		i;
	char	*n1_str;
	char	*n2_str;

	i = 20;
	while (++i < 100)
	{
		if (i % 10 != 0)
		{
			n2_str = g_unique_map[i % 10];
			n1_str = g_unique_map[i - (i % 10)];
			g_unique_map[i] = NULL;
			if (!n2_str || !n1_str)
				continue ;
			g_unique_map[i] = ft_malloc_map(n1_str, n2_str, 0);
			ft_strcat(g_unique_map[i], n1_str);
			ft_strcat(g_unique_map[i], n2_str);
		}
	}
	return (0);
}

int	ft_fill_3num_map(void)
{
	int		i;
	char	*n1_str;
	char	*n2_str;
	char	*n3_str;

	i = 100;
	while (++i < 1000)
	{
		n1_str = g_unique_map[i / 100];
		n2_str = g_unique_map[100];
		n3_str = g_unique_map[i % 100];
		if (!n1_str || !n2_str || !n3_str)
			continue ;
		if (i % 100 == 0)
			n3_str = 0;
		g_unique_map[i] = NULL;
		g_unique_map[i] = ft_malloc_map(n1_str, n2_str, n3_str);
		ft_strcat(g_unique_map[i], n1_str);
		ft_strcat(g_unique_map[i], n2_str);
		ft_strcat(g_unique_map[i], n3_str);
	}
	return (0);
}
