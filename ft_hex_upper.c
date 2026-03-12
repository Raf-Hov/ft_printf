/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_upx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafhovha <rafhovha@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:18:13 by rafhovha          #+#    #+#             */
/*   Updated: 2026/03/12 21:30:06 by rafhovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_upper(unsigned int n)
{
	char	c;
	int		len;
	int		res;

	len = 0;
	if (n >= 16)
	{
		res = ft_put_upper(n / 16);
		if (res < 0)
			return (-1);
		len += res;
	}
	if ((n % 16) < 10)
		c = (n % 16) + '0';
	else
		c = (n % 16) - 10 + 'A';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_hex_upx(unsigned int i)
{
	if (i == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	return (ft_put_upper(i));
}
