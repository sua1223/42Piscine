/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:45:22 by jonkim            #+#    #+#             */
/*   Updated: 2021/10/24 12:28:48 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"rush02.h"

char	**g_unique_map;
int		ft_fill_2num_map(void);
int		ft_fill_3num_map(void);

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	if (!src)
		return (NULL);
	i = ft_strlen(dest);
	j = 0;
	if (i != 0)
	{
		dest[i] = ' ';
		i++;
	}
	while (src[j] != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}

char	*get_t_map_value(int n)
{
	int	i;

	i = 0;
	while (g_number_map[i] != NULL)
	{
		if (g_number_map[i]->num == n)
			return (g_number_map[i]->value);
		i++;
	}
	return (NULL);
}

char	*ft_malloc_map(char *str1, char *str2, char *str3)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (str1)
		len = ft_strlen(str1);
	if (str2)
		len += ft_strlen(str2) + 1;
	if (str3)
		len += ft_strlen(str3) + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		write(1, "memory allocation fail!", 23);
		return (NULL);
	}
	while (i < len + 1)
	{
		str[i++] = 0;
	}
	return (str);
}

void	char_map_init(void)
{
	int	i;

	i = -1;
	while (++i <= 100)
	{
		if (i < 20)
		{
			if (!get_t_map_value(i))
				continue ;
			g_unique_map[i] = ft_malloc_map(get_t_map_value(i), 0, 0);
			ft_strcat(g_unique_map[i], get_t_map_value(i));
		}
		else if (i % 10 == 0)
		{
			if (!get_t_map_value(i))
				continue ;
			g_unique_map[i] = ft_malloc_map(get_t_map_value(i), 0, 0);
			ft_strcat(g_unique_map[i], get_t_map_value(i));
		}
	}
	g_unique_map[1000] = 0;
}

int	fill_char_map(void)
{
	g_unique_map = (char **)malloc(1001 * sizeof(char *));
	if (!g_unique_map)
	{
		write(1, "memory allocation error", 23);
		return (-1);
	}
	char_map_init();
	ft_fill_2num_map();
	ft_fill_3num_map();
	return (0);
}
