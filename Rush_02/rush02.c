#include <unistd.h>

int validate_input(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
		{
			write(1, "Error", 5); // print error message
			return -1;
		}
		i++;
	}
	return 1;
}

int	ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str != '\0')
		i++;
	return (i);
}

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int atoi(char *str)
{
	int result;
	int i;

	i = -1;
	while (++i < 3)
	{
		if (str[i] == 'a')
			continue;
		else
		{
			result = str[i] - '0';
			break;
		}
	}

	while (++i<3)
	{
		result *= 10;
		result += str[i] - '0';
	}
	return result;
}

int calc_set_hun(int num)
{
	//find_unique(num / 100);
	printf("%d\n", num / 100);
	//find_unique(100);
	printf("100\n");
	num %= 100;

	return num;
}

int calc_set_ten(int num, char *str)
{
	if (str[1] < '2' || str[2] == '0')
	{
		//find_unique(num);
		printf("%d\n", num);
		num = 0;
	}
	else
	{
		//find_unique(num / 10);
		printf("%d\n", num / 10);
		num %= 10;
	}
	return num;
}

void calc_set(char *str)
{
	int i;
	int num;

	i = -1;
	num = atoi(str);
	while (i++ < 3 && num != 0)
	{
		if (str[i] == 'a' || str[i] == '0')
			continue;
		else if (i == 0)
			num = calc_set_hun(num);
		else if (i == 1)
			num = calc_set_ten(num, str);
		else if (i == 2)
		{
			//find_unique(num);
			printf("%d\n", num);
			num = 0;
		}
	}
}

void parsing(char *str)
{
	int len;
	int i;
	int j;
	int digit;
	int k;
	int flag;

	char set[3] = { 'a','a','a' };

	len = ft_strlen(str);
	if (len % 3 == 0)
	{
		digit = len / 3;
		flag = 0;
	}
	else
	{
		digit = len / 3 + 1;
		flag = 1;
	}

	j = 0;
	while (digit-- > 0)
	{
		i = -1;
		while (++i < 3)
		{
			if (flag == 1)
			{
				k = -1;
				while (++k < 3 - len % 3)
					i++;
				flag = 0;
			}
			set[i] = str[j];
			j++;
		}
		calc_set(set);
		//find_digit(digit);
	}
}

int	main(int argc, char *argv[])
{
	int len;

	if (argc == 3)
	{
		// change dict
	}	
	else if (argc == 2)
	{	
		// need to check init func param
		if(validate_input(argv[1]) && init(dict) && fill_map())
		{
			parsing(argv[1]);		
		}
		else
			return -1;
	}
}
