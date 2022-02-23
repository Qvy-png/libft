/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:33:38 by rdel-agu          #+#    #+#             */
/*   Updated: 2021/12/06 21:33:44 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned int ui, char *base)
{
	if (ui < 0)
	{
		ft_putchar('-');
		ui = -ui;
	}
	if (ui >= 16)
		ft_hexa(ui / 16, base);
	ft_putchar(base[ui % 16]);
}

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len ++;
		n = n / 16;
	}
	return (len);
}

int	ft_puthex(va_list a, char *base)
{
	int	i;

	i = va_arg(a, int);
	ft_hexa(i, base);
	return (ft_hexlen(i));
}
