/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafhovha <rafhovha@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:18:09 by rafhovha          #+#    #+#             */
/*   Updated: 2026/03/12 22:00:53 by rafhovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hex_cri(void *s)
{
	char	*str;

	str = malloc(hex_hashiv(s) + 3);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

static void	esim_e(unsigned long l, size_t index, char *str)
{
	if (l == 10)
		str[index] = 'a';
	else if (l == 11)
		str[index] = 'b';
	else if (l == 12)
		str[index] = 'c';
	else if (l == 13)
		str[index] = 'd';
	else if (l == 14)
		str[index] = 'e';
	else if (l == 15)
		str[index] = 'f';
}

static void	fill_hex_str(unsigned long k, size_t len, char *str)
{
	while (len > 1)
	{
		if (k % 16 >= 10 && k % 16 <= 15)
		{
			esim_e(k % 16, len, str);
			len--;
			k = k / 16;
		}
		else
		{
			str[len] = (k % 16) + '0';
			k = k / 16;
			len--;
		}
	}
}

static char	*hex_lcnel(void *s)
{
	char			*str;
	size_t			len;
	unsigned long	k;

	k = (unsigned long)s;
	str = hex_cri(s);
	if (!str)
		return (NULL);
	len = hex_hashiv(s) + 2;
	str[len--] = '\0';
	fill_hex_str(k, len, str);
	return (str);
}

int	ft_hex_p(void *s)
{
	char	*str;
	int		lk;

	if (!s)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	str = hex_lcnel(s);
	if (!str)
		return (-1);
	lk = write_ptr_str(str);
	free(str);
	return (lk);
}
