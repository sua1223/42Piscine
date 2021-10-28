/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:47:27 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 01:47:28 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	file_size(char *file)
{
	int		total;
	char	buf[BUF_SIZE];
	int		fd;
	int		size;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (-1);
	size = read(fd, buf, BUF_SIZE);
	total = 0;
	while (size > 0)
	{
		total += size;
		size = read(fd, buf, BUF_SIZE);
	}
	if (fd > 3)
		close(fd);
	if (size < 0)
		return (-1);
	return (total);
}

char	*read_file(char *file)
{
	char	*dst;
	int		total;
	int		fd;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (NULL);
	total = file_size(file);
	dst = (char *) malloc(sizeof(char *) * (total + 1));
	if (!dst)
		return (dst);
	dst[total] = '\0';
	if (read(fd, dst, total) < 0)
	{
		free(dst);
		dst = NULL;
	}
	if (fd > 3)
		close(fd);
	return (dst);
}

char	**get_lines(char *file)
{
	char	*content;
	char	**words;

	content = read_file(file);
	words = ft_split(content, '\n');
	free(content);
	return (words);
}
