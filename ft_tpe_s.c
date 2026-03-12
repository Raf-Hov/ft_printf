/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpe_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafhovha <rafhovha@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:18:27 by rafhovha          #+#    #+#             */
/*   Updated: 2026/03/12 20:18:28 by rafhovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tpe_s(char *s)
{
	int		i;
	int		len;
	char	*str;

	if (!s)
		str = "(null)";
	else
		str = s;
	i = 0;
	len = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
		len++;
	}
	return (len);
}
