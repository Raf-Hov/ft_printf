#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		word[len] = s[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_all(char **arr, size_t i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

static size_t	fill_result(char **result, char const *s, char c, size_t wc)
{
	size_t	i;

	i = 0;
	while (i < wc)
	{
		while (*s == c)
			s++;
		result[i] = get_word(s, c);
		if (!result[i])
			return (i);
		while (*s && *s != c)
			s++;
		i++;
	}
	result[i] = NULL;
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;
	size_t	filled;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	filled = fill_result(result, s, c, word_count);
	if (filled != word_count)
	{
		free_all(result, filled);
		return (NULL);
	}
	return (result);
}
