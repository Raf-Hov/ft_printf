#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	len = ft_strlen(s);
	new = malloc(len * sizeof(char) + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
