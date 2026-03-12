#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*k;
	size_t	l;
	size_t	max_l;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	max_l = ft_strlen(s + start);
	if (len > max_l)
		len = max_l;
	k = malloc(len + 1);
	if (!k)
		return (NULL);
	l = 0;
	while (l < len)
	{
		k[l] = s[start + l];
		l++;
	}
	k[l] = '\0';
	return (k);
}
