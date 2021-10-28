/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:02:40 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/23 10:02:41 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# define BUF_SIZE 4096 

typedef struct s_map
{
	char	*key;
	char	*value;
	int		num;
	int		digit;
}	t_map;

extern t_map		**g_number_map;

extern t_map		**g_digit_map;

extern char			**g_unique_map;

// error == -1
int		init(char *dict);

char	**split_by_sep(char *str, char sep);

t_map	**get_dict(char *file);

char	*find_digit(int n);

char	*find_unique(int n);

int		validate_input(char *str);
char	**ft_split(char *str, char c);
int		ft_strlen(char *str);
void	f_memcpy(void *dst, void *src, unsigned int len);
char	*strip(char *word);
char	*lstrip(char *word);
int		count_arr(char **strs);
int		ft_atoi(char *str);
void	free_list(t_map **list);
void	free_words(char **strs);
char	**get_lines(char *file);
t_map	*creat_elem(char *key, char *val);
int		add_elem(char **words, t_map **list, int idx);
int		validate_key(char *key);
int		validate_map(char **words);
int		fill_char_map(void);
int		validate_digit(char *digit);
char	*find_digit(int digit);
void	f_print(char *str);
char	*ft_malloc_map(char *str1, char *str2, char *str3);
char	*ft_strcat(char *dest, char *src);
int		validate_input(char *str);
int		validate_elem(int digit, int offset, char *set, char *str);
void	clear_set(char *set);
void	free_all(void);
#endif 
