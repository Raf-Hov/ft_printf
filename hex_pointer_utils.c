/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pr_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafhovha <rafhovha@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:25:58 by rafhovha          #+#    #+#             */
/*   Updated: 2026/03/12 20:25:58 by rafhovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_ptr_str(char *str)
{
	size_t	index;
	int		lk;

	index = 0;
	lk = 0;
	while (str[index])
	{
		if (write(1, &str[index], 1) == -1)
			return (-1);
		index++;
		lk++;
	}
	return (lk);
}

size_t	hex_hashiv(void *s)
{
	unsigned long	k;
	size_t			count;

	k = (unsigned long)s;
	count = 1;
	while (k >= 16)
	{
		k /= 16;
		count++;
	}
	return (count);
}
