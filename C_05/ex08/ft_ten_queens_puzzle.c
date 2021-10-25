#include <unistd.h>

int	is_okay(int *pos, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (pos[i] == pos[j])
			return (0);
		if (i - j == pos[i] - pos[j])
			return (0);
		if (i - j == -pos[i] + pos[j])
			return (0);
		j++;
	}
	return (1);
}

void	print_queens(int *pos)
{
	int		i;
	char	index;

	i = 0;
	while (i < 10)
	{
		index = pos[i] + '0';
		write(1, &index, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ten_queens(int *pos, int i, int cur, int *result)
{
	if (i == 10)
	{
		print_queens(pos);
		(*result)++;
		return ;
	}
	while (cur < 10)
	{
		pos[i] = cur;
		if (is_okay(pos, i))
			ten_queens(pos, i + 1, 0, result);
		cur++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];
	int	result;

	result = 0;
	ten_queens(pos, 0, 0, &result);
	return (result);
}
