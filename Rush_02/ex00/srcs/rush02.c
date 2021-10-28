/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:37:06 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 13:37:06 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	clear_set(char *set)
{
	int	i;

	i = -1;
	while (++i < 3)
		set[i] = ' ';
}

void	print_value(int j, char *set, int digit)
{
	if (j != 0 && ft_atoi(set))
		f_print(" ");
	if (ft_atoi(set))
		f_print(g_unique_map[ft_atoi(set)]);
	if (digit)
	{
		f_print(" ");
		f_print(find_digit(digit));
	}
}

int	parse_print(int digit, int offset, char *set, char *str)
{
	int	i;
	int	j;

	j = 0;
	if (digit == 1 && str[0] == '0')
	{
		f_print(g_unique_map[0]);
		digit = 0;
	}
	while (digit--)
	{
		clear_set(set);
		i = offset;
		if (offset != 0)
			offset = 0;
		f_memcpy(&set[i], &str[j], 3 - i);
		if (!g_unique_map[ft_atoi(set)])
			return (-1);
		print_value(j, set, digit);
		j += 3 - i;
	}
	f_print("\n");
	return (1);
}

int	parsing(char *str)
{
	int		len;
	int		digit;
	int		offset;
	char	set[4];

	len = ft_strlen(str);
	offset = len % 3;
	if (offset)
		offset = 3 - offset;
	if (len % 3 == 0)
		digit = len / 3;
	else
		digit = len / 3 + 1;
	if (validate_elem(digit, offset, set, str) == -1)
		return (-1);
	return (parse_print(digit, offset, set, str));
}

int	main(int ac, char **av)
{
	char	*dict;
	int		idx;
	int		ret;

	idx = 1;
	ret = 0;
	dict = NULL;
	if (ac == 3)
	{
		idx = 2;
		dict = av[1];
	}
	else if (ac == 2)
		dict = "numbers.dict";
	ret = (ac == 1 || ac > 3 || validate_input(av[idx]) == -1);
	if (!ret)
		ret = (init(dict) == -1 || parsing(av[idx]) == -1) * 2;
	if (ret == 1)
		f_print("Error\n");
	if (ret == 2)
		f_print("Dict Error\n");
	free_all();
	return (ret);
}
