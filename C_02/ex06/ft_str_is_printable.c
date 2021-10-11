#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
			flag = 1;
		i++;
	}
	if (flag == 0 || i == 0)
		return (1);
	else
		return (0);
}
