#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	char	*k;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	k = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!k)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		k[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		k[i++] = s2[j++];
	k[i] = '\0';
	return (k);
}
