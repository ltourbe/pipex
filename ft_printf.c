/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltourbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:48:53 by ltourbe           #+#    #+#             */
/*   Updated: 2025/11/28 14:13:05 by ltourbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	if (!str)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_printf2(str[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	ft_printf2(char c, va_list args)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_hexaddress(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_lowhexa(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_upphexa(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_percent();
	return (count);
}
/*
int	main(void)
{
	int x = 42;
	void *ptr;

	ptr = &x;
	ft_printf("%p\n", ptr);
	printf("%p\n", ptr);
}*/