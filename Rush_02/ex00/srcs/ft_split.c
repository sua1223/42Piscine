/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:25:41 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/19 21:25:42 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strncpy(char *dst, char *src, int len)
{
	while (*src && len--)
		*dst++ = *src++;
	*dst = '\0';
}

int	is_seperator(char s, char c)
{
	return (c == s);
}

int	count_words(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (is_seperator(str[i], c))
		{
			i++;
			continue ;
		}
		words++;
		while (str[i] && !is_seperator(str[i], c))
			i++;
	}
	return (words);
}

char	**split_words(char *str, char c, char **dst)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (str[j])
	{
		while (is_seperator(str[j], c))
			j++;
		size = 0;
		if (!str[j])
			break ;
		while (str[j + size] && !is_seperator(str[j + size], c))
			size++;
		dst[i] = (char *) malloc(sizeof(char) * (size + 1));
		if (!dst[i])
			return (NULL);
		ft_strncpy(dst[i], &str[j], size);
		j += size;
		i++;
		if (!str[j])
			break ;
	}
	return (dst);
}

char	**ft_split(char *str, char c)
{
	char	**dst;

	if (str == NULL)
		return (NULL);
	dst = (char **) malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!dst)
		return (NULL);
	dst[count_words(str, c)] = 0;
	return (split_words(str, c, dst));
}
