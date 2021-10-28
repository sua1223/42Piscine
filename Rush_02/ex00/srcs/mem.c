/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 02:13:27 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 02:13:28 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	f_memcpy(void *dst, void *src, unsigned int len)
{
	char			*to;
	char			*from;
	unsigned int	i;

	to = (char *) dst;
	from = (char *) src;
	i = 0;
	while (i < len)
	{
		to[i] = from[i];
		i++;
	}
}

void	free_list(t_map **list)
{
	int	i;

	i = -1;
	if (!list)
		return ;
	while (list[++i])
	{
		free(list[i]->key);
		free(list[i]->value);
		free(list[i]);
	}
	free(list);
}

void	free_words(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_all(void)
{
	free_list(g_number_map);
	free_list(g_digit_map);
	free_words(g_unique_map);
}
