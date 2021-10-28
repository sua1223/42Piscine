/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:48:27 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/23 19:48:28 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_map	**g_number_map;
t_map	**g_digit_map;
char	**g_unique_map;

int	alloc_maps(t_map **list, int size)
{
	int	digits;
	int	i;

	digits = 0;
	i = -1;
	while (++i < size)
		digits += ft_strlen(list[i]->key) > 3;
	g_digit_map = (t_map **) malloc(sizeof(t_map *) * (digits + 1));
	if (!g_digit_map)
	{
		free_list(list);
		return (-1);
	}
	g_digit_map[digits] = NULL;
	g_number_map = (t_map **) malloc(sizeof(t_map *) * (size - digits + 1));
	if (!g_number_map)
	{
		free(g_number_map);
		free_list(list);
		return (-1);
	}
	g_number_map[size - digits] = NULL;
	return (1);
}

int	split_map(t_map **list, int size)
{
	int	i;
	int	digits;
	int	numbers;

	if (alloc_maps(list, size) == -1)
		return (-1);
	digits = 0;
	numbers = 0;
	i = -1;
	while (++i < size)
	{
		if (ft_strlen(list[i]->key) > 3)
			g_digit_map[digits++] = list[i];
		else
			g_number_map[numbers++] = list[i];
	}
	free(list);
	return (1);
}

int	parse_element(t_map **list, char **words, int len)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < len)
	{
		if (add_elem(ft_split(words[j], ':'), list, i++) == -1)
		{
			free_list(list);
			free_words(words);
			return (-1);
		}
	}
	return (i);
}

int	fill_map(char *file)
{
	t_map	**list;
	char	**words;
	int		len;
	int		size;

	words = get_lines(file);
	if (!words)
		return (-1);
	len = count_arr(words);
	list = (t_map **) malloc(sizeof(t_map *) * (len + 1));
	list[len] = NULL;
	if (!list)
		return (-1);
	size = parse_element(list, words, len);
	if (size == -1)
		return (-1);
	free_words(words);
	split_map(list, size);
	return (1);
}

int	init(char *name)
{
	if (fill_map(name) == -1)
		return (-1);
	if (fill_char_map() == -1)
		return (-1);
	return (1);
}
