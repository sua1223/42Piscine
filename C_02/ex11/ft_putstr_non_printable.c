#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	 int	neg;

	hex = "0123456789abcdef";
	while (*str)
	{
		if (*str <= 31 || *str >= 127)
		{
			write(1, "\\", 1);
			if (*str < 0)
			{
				neg = (-128 - (*str)) * -1 + 128;
				write(1, &hex[neg / 16], 1);
				write(1, &hex[neg % 16], 1);
			}
			else
			{
				write(1, &hex[*str / 16], 1);
				write(1, &hex[*str % 16], 1);
			}
		}
		else
			write(1, str, 1);
		str++;
	}
}
