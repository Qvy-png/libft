/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:45:07 by rdel-agu          #+#    #+#             */
/*   Updated: 2021/12/07 08:27:47 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long long n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	ft_number_disp(va_list a)
{
	long long	n;
	int			i;

	i = 0;
	n = va_arg(a, int);
	ft_putnbr(n);
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_unsilen(unsigned int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return (1);
	while (len != 0)
	{
		len = len / 10;
		i++;
	}
	return (i);
}

void	ft_putunsi(unsigned int u)
{
	char	c;

	c = (u % 10) + '0';
	if (u >= 10)
	{
		ft_putunsi(u / 10);
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}

int	ft_unsi_disp(va_list a)
{
	int	i;

	i = va_arg(a, unsigned int);
	ft_putunsi(i);
	return (ft_unsilen(i));
}
