#include "libft.h"

static int	hashvel(long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*min_ito2(long n)
{
	char	*str;
	int		k;

	n *= -1;
	k = hashvel(n);
	str = malloc(k * sizeof(char) + 2);
	if (!str)
		return (NULL);
	str[k + 1] = '\0';
	while (n > 0)
	{
		str[k--] = (n % 10) + '0';
		n /= 10;
	}
	str[k] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
		return (min_ito2(num));
	len = hashvel(num);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
