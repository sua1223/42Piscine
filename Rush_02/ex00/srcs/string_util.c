/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:57:12 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 01:57:13 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	f_print(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*strip(char *word)
{
	char	*dst;
	int		size;
	int		i;
	int		j;

	if (!word)
		return (NULL);
	i = 0;
	size = ft_strlen(word);
	j = size - 1;
	while (word[i] == ' ')
		i++;
	while (word[j] == ' ')
		j--;
	size = j - i + 1;
	dst = (char *) malloc(sizeof(char) * (size + 1));
	if (dst)
	{
		dst[size] = '\0';
		f_memcpy(dst, &word[i], size);
	}
	return (dst);
}

char	*lstrip(char *word)
{
	char	*dst;
	int		j;
	int		i;

	if (!word)
		return (NULL);
	i = 0;
	while (word[i] == ' ')
		i++;
	j = ft_strlen(word);
	if (!i)
		return (NULL);
	dst = (char *) malloc(sizeof(char) * (j - i + 1));
	if (!dst)
		return (NULL);
	dst[j - i + 1] = '\0';
	f_memcpy(dst, &word[i], j - i);
	return (dst);
}

int	count_arr(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
