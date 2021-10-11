#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] !='\0');
	{
		if (str[i] < 'a' && str[i] >'Z')
			flag = 1;
		else if (str[i] < 'A' || str[i] > 'z')
			flag = 1;	
		i++;
	}
	if (flag == 1 || i == 0)
		return(1);
	else
		return(0);
}
