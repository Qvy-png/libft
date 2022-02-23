/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_charstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:19:28 by rdel-agu          #+#    #+#             */
/*   Updated: 2021/12/06 19:48:12 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{	
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_cpchar(va_list a)
{
	char	c;

	c = (char)va_arg(a, int);
	return (ft_putchar(c));
}

int	ft_cpstr(va_list a)
{
	int		i;
	char	*s;

	s = (char *)va_arg(a, int *);
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = ft_putstr(s);
	return (i);
}
