/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafhovha <rafhovha@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 21:28:06 by rafhovha          #+#    #+#             */
/*   Updated: 2026/03/12 21:28:07 by rafhovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define ARGER "cspdiuxX%"

int		ft_printf(const char *str, ...);

int		ft_dpri(int i);
int		ft_hex_p(void *s);
int		ft_hex_upx(unsigned int i);
int		ft_hex_x(unsigned int i);
int		ft_putchar(char c);
int		ft_tpe_s(char *s);
int		ft_upri(unsigned int i);
int		write_ptr_str(char *str);
size_t	hex_hashiv(void *s);

#endif