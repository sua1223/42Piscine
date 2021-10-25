#include <stdlib.c>

int	*ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*arr;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len + 1);
	if (arr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		arr[i] = min;
		i++;
		min++;
	}
	*range = arr;
	return (i);

	
}

