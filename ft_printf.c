/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafhovha <rafhovha@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:18:17 by rafhovha          #+#    #+#             */
/*   Updated: 2026/03/12 21:32:44 by rafhovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list *args, char specifier)
{
	if (specifier == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	if (specifier == 's')
		return (ft_tpe_s(va_arg(*args, char *)));
	if (specifier == 'p')
		return (ft_hex_p(va_arg(*args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_dpri(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_upri(va_arg(*args, unsigned int)));
	if (specifier == 'x')
		return (ft_hex_x(va_arg(*args, unsigned int)));
	if (specifier == 'X')
		return (ft_hex_upx(va_arg(*args, unsigned int)));
	if (specifier == '%')
		return ((int)write(1, "%", 1));
	return (0);
}

static int	ft_print_str(const char *str, va_list *args)
{
	size_t	i;
	int		count;
	int		writed;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			writed = ft_format(args, str[i + 1]);
			if (writed < 0)
				return (-1);
			count += writed;
			i += 2;
		}
		else
		{
			if (write(1, &str[i], 1) == -1)
				return (-1);
			count++;
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	if (!str)
		return (-1);
	va_start(args, str);
	result = ft_print_str(str, &args);
	va_end(args);
	return (result);
}
