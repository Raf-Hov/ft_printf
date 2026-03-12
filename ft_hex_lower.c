/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafhovha <rafhovha@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:18:15 by rafhovha          #+#    #+#             */
/*   Updated: 2026/03/12 21:35:01 by rafhovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex_lower(unsigned int n)
{
	char	c;
	int		len;
	int		res;

	len = 0;
	if (n >= 16)
	{
		res = ft_put_hex_lower(n / 16);
		if (res < 0)
			return (-1);
		len += res;
	}
	if ((n % 16) < 10)
		c = (n % 16) + '0';
	else
		c = (n % 16) - 10 + 'a';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}

int	t_hex_x(unsigned int i)
{
	if (i == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	return (ft_put_hex_lower(i));
}
