/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:10:27 by rdel-agu          #+#    #+#             */
/*   Updated: 2021/12/07 08:24:59 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//inclusion of external libraries
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

//first part, cspdiuxX%

int	ft_cpchar(va_list a);
int	ft_cpstr(va_list a);
int	ft_number_disp(va_list a);
int	ft_putchar(char c);
int	ft_unsi_disp(va_list a);
int	ft_point_disp(va_list q);
int	ft_printf(const char *s, ...);
int	ft_puthex(va_list a, char *base);
#endif
