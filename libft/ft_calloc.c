#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t			i;
	unsigned char	*s;
	size_t			l;

	i = 0;
	l = nelem * elsize;
	if (elsize > SIZE_MAX / nelem && nelem != 0)
		return (NULL);
	s = (unsigned char *)malloc(l);
	if (!s)
		return (NULL);
	while (i < l)
	{
		s[i] = 0;
		i++;
	}
	return ((void *)s);
}
