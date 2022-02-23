/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:14:10 by rdel-agu          #+#    #+#             */
/*   Updated: 2021/12/07 08:26:50 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat(va_list a, char c)
{
	int	t;

	t = 0;
	if (c == 'c')
		t += ft_cpchar(a);
	else if (c == 's')
		t += ft_cpstr(a);
	else if (c == 'p')
		t += ft_point_disp(a);
	else if (c == 'd' || c == 'i')
		t += ft_number_disp(a);
	else if (c == 'u')
		t += ft_unsi_disp(a);
	else if (c == 'x')
		t += ft_puthex(a, "0123456789abcdef");
	else if (c == 'X')
		t += ft_puthex(a, "0123456789ABCDEF");
	else if (c == '%')
		t += ft_putchar('%');
	return (t);
}

int	type(const char *s, va_list a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			j = j + treat(a, s[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			j++;
		}
		i++;
	}
	return (j);
}

int	ft_printf(const char *s, ...)
{
	va_list	a;
	int		i;

	i = 0;
	va_start(a, s);
	i = type(s, a);
	va_end(a);
	return (i);
}
