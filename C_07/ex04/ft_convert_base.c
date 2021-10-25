#include <stdlib.h>

int	ft_strlen(char *str);
int	is_space(char c);
int	base_loc(char *base, char c);
int	is_valid(char *base);
int	ft_atoi_base(char *str, char *base);
char	*g_str;
int	g_idx;

int	nbr_size(long long nbr, int base_len)
{
	int	res_size;

	if (!nbr)
		return (1);
	res_size = 0;
	if (nbr < 0)
		++res_size;
	while (nbr)
	{
		nbr /= base_len;
		++res_size;
	}
	return (res_size);
}

void	print_base(int n, char *base, int base_len)
{
	if (n >= base_len)
		print_base(n / base_len, base, base_len);
	g_str[g_idx++] = base[n % base_len];
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	
	g_idx = 0;
	if (!is_valid(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		g_str[g_idx++] = '-';
		print_base(2147483648 / base_len, base, base_len);
		return ;
	}
	if (nbr < 0)
	{
		g_str[g_idx++] = '-';
		nbr *= -1;
	}
	print_base(nbr, base, base_len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;
	int		size;
	int		convert_num;
	char		*result;

	num = nbr;
	size = nbr_sizenum, ft_strlen(base);
	g_str = (char *)malloc(sizeof(char) * (size + 1));
	g_str[size] = 0;
	if(!is_valid(base_from) || !is_valid(base_to))
		return (NULL);
	convert_num = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(convert_num, base_to);
	return (result);
}
