/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:51:12 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 01:51:13 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	validate_key(char *key)
{
	if (!key)
		return (-1);
	while (*key && *key == ' ')
		key++;
	while ('0' <= *key && *key <= '9')
		key++;
	while (*key == ' ')
		key++;
	if (*key)
		return (-1);
	return (1);
}

int	validate_map(char **words)
{
	if (count_arr(words) != 2)
		return (-1);
	if (validate_key(words[0]) == -1)
		return (-1);
	return (1);
}

int	validate_digit(char *digit)
{
	if (*digit++ != '1')
		return (-1);
	while (*digit)
	{
		if (*digit++ != '0')
			return (-1);
	}
	return (1);
}

int	validate_input(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 1 && str[0] == '0')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	validate_elem(int digit, int offset, char *set, char *str)
{
	int	i;
	int	j;

	j = 0;
	if (digit == 1 && str[0] == '0')
	{
		if (g_unique_map[0] == NULL)
			return (-1);
		return (1);
	}
	while (digit--)
	{
		clear_set(set);
		i = offset;
		if (offset != 0)
			offset = 0;
		f_memcpy(&set[i], &str[j], 3 - i);
		if (!g_unique_map[ft_atoi(set)]
			|| (digit > 0 && !find_digit(digit)))
			return (-1);
		j += 3 - i;
	}
	return (1);
}
