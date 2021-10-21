/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujang <sujang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:24:53 by sujang            #+#    #+#             */
/*   Updated: 2021/10/14 12:26:44 by sujang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alpha_num(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	else if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

char	ft_strupcase(char c)
{
	if (c <= 'z' && c >= 'a')
		c = c - 32;
	return (c);
}

char	ft_strlowcase(char c)
{
	if (c <= 'Z' && c >= 'A')
		c = c + 32;
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		if (i == 0 || !(is_alpha_num(str[i - 1])))
			str[i] = ft_strupcase(str[i]);
		else
			str[i] = ft_strlowcase(str[i]);
		i++;
	}
	return (str);
}
