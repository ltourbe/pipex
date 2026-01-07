/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltourbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:20:23 by ltourbe           #+#    #+#             */
/*   Updated: 2025/11/27 15:20:24 by ltourbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	ft_hexaddress(void *ptr)
{
	size_t			count;
	unsigned long	address;

	count = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		address = (unsigned long)ptr;
		count += ft_putstr("0x");
		count += ft_lowhexa(address);
	}
	return (count);
}

int	ft_putnbr(int i)
{
	long int	filou;
	long int	res;
	size_t		count;

	count = 0;
	filou = i;
	if (filou < 0)
	{
		filou = -filou;
		write(1, "-", 1);
		count++;
	}
	if (filou < 10)
	{
		res = filou + '0';
		write(1, &res, 1);
		count++;
	}
	else
	{
		count += ft_putnbr(filou / 10);
		count += ft_putnbr(filou % 10);
	}
	return (count);
}

int	ft_unsigned_putnbr(unsigned int i)
{
	size_t		count;
	long int	res;

	count = 0;
	if (i < 10)
	{
		res = i + '0';
		write(1, &res, 1);
		count++;
	}
	else
	{
		count += ft_unsigned_putnbr(i / 10);
		count += ft_unsigned_putnbr(i % 10);
	}
	return (count);
}
