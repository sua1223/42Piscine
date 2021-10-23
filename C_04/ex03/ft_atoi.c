#include <stdio.h>

int isDigit(char c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}

int isSigned(char *str)
{
	int i;
	int cnt;
	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			cnt++;
		i++;
	}
	return (cnt);
}

int startIndex(char *str)
{
	int i;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		if (isDigit(str[i]))
			return(i);
		else
			return(-1);
	}
	return (0);
}

int init(char *str)
{
	int i;
	int result;
	i = 0;
	while (str[i] != '\0')
	{
		if(isDigit(str[i]))
		{
			result = str[i] - '0';
			return (result);
		}
		i++;
	}
	return (-1);
}

int ft_atoi(char *str)
{
	int idx;
	int result;
	int minus;

	idx = startIndex(str)-1;
	minus = isSigned(str);
	result = init(str);
	if (idx == -1 || result == -1)
		return (0);
	while (str[idx] != '\0')
	{
		if (isDigit(str[idx]))
		{
			result *= 10;
			result += str[idx];
		}
		else
			break;
		idx++;				
	}
	if (minus == 1)
		return (result * -1);
	return (result);
}

int main()
{
	int result;
	char test[] = "   ---+--+1234ab567";

	result = ft_atoi(test);
	printf("%d\n", result);
}
