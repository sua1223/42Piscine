#include <unistd.h>

void	print_addr(unsigned long long addr, unsigned int cnt, char *hex)
{
	if (addr != 0)
	{
		addr_hex(addr / 16, cnt + 1, hex);
		write(1, &hex[addr % 16], 1);
	}
	else
	{
		while (cnt < 16)
		{
			write(1, "0", 1);
			cnt ++;
		}
	}
}

void	print_char(unsigned char *addr, unsigned int len, char *hex, char *str)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (' ' <= addr[i] && addr[i] <= '~')
			str[i] = addr[i];
		else
			str[i] = '.';
		write(1, &hex[(int)addr[i] / 16], 1);
		write(1, &(hex[(int)addr[i] % 16], 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*hex;
	unsigned int	tmp;
	char			str[16];

	hex = "0123456789abcdef";
	i = 0;
	while (size > 0)
	{
		if (size > 16)
			tmp = 16;
		else
			tmp = size;
		print_addr((unsigned long long)addr + i, 0, hex);
		write(1, ":", 1);
		print_char((unsigned char *)addr + i, tmp, hex, str);
		write(1, " ", 1);
		write(1, str, tmp);
		write(1, "\n", 1);
		size -= tmp;
		i += 16;
	}
}
