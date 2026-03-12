#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*ktrv;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	ktrv = (char *)malloc(len + 1);
	if (!ktrv)
		return (NULL);
	ft_memmove(ktrv, s1 + start, len);
	ktrv[len] = '\0';
	return (ktrv);
}
