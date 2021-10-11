#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	i;
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
