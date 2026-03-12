/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafhovha <rafhovha@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:16:13 by rafhovha          #+#    #+#             */
/*   Updated: 2026/03/12 20:16:14 by rafhovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dpri(int i)
{
	char	*str;
	size_t	k;
	int		lk;

	str = ft_itoa(i);
	if (!str)
		return (-1);
	k = 0;
	lk = 0;
	while (str[k])
	{
		if (write(1, &str[k], 1) == -1)
		{
			free(str);
			return (-1);
		}
		k++;
		lk++;
	}
	free(str);
	return (lk);
}
