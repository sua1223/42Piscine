#include <stdlib.c>

int	*ft_range(int min, int max)
{
	int	len;
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len + 1);
	i = 0;
	while (i < len)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);

	
}
