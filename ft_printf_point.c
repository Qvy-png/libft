/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:35:48 by rdel-agu          #+#    #+#             */
/*   Updated: 2021/12/07 08:25:37 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpoint(unsigned long ul, char *base)
{
	if (ul >= 16)
		ft_putpoint(ul / 16, base);
	ft_putchar(base[ul % 16]);
}

int	ft_pointlen(unsigned long ul)
{
	int	i;

	i = 0;
	while (ul != 0)
	{
		i++;
		ul = ul / 16;
	}
	return (i);
}

int	ft_point_disp(va_list a)
{
	unsigned long	i;

	i = va_arg(a, unsigned long);
	ft_putchar('0');
	ft_putchar('x');
	ft_putpoint(i, "0123456789abcdef");
	if (!i)
		return (ft_pointlen(i) + 3);
	else
		return (ft_pointlen(i) + 2);
}
