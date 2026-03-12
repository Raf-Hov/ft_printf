/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafhovha <rafhovha@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:18:30 by rafhovha          #+#    #+#             */
/*   Updated: 2026/03/12 20:18:31 by rafhovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_unsigned(unsigned int n)
{
	char	c;
	int		len;
	int		res;

	len = 0;
	if (n >= 10)
	{
		res = ft_put_unsigned(n / 10);
		if (res < 0)
			return (-1);
		len += res;
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_upri(unsigned int i)
{
	if (i == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	return (ft_put_unsigned(i));
}
