/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:53:00 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 01:53:00 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_map	*creat_elem(char *key, char *val)
{
	t_map	*node;

	node = (t_map *) malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = val;
	return (node);
}

int	add_elem(char **words, t_map **list, int idx)
{
	if (validate_map(words) == -1)
		return (-1);
	list[idx] = creat_elem(strip(words[0]), lstrip(words[1]));
	if (!list[idx] || !list[idx]->key || !list[idx]->value)
		return (-1);
	if (ft_strlen(list[idx]->key) <= 3)
		list[idx]->num = ft_atoi(list[idx]->key);
	else
	{
		if (validate_digit(list[idx]->key) != -1)
			list[idx]->digit = ft_strlen(list[idx]->key) / 3;
	}
	free_words(words);
	return (1);
}

char	*find_digit(int digit)
{
	int	i;

	i = -1;
	while (g_digit_map[++i])
	{
		if (g_digit_map[i]->digit == digit)
			return (g_digit_map[i]->value);
	}
	return (NULL);
}
