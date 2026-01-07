/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltourbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:10:38 by ltourbe           #+#    #+#             */
/*   Updated: 2025/11/27 16:10:40 by ltourbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowhexa(unsigned long i)
{
	size_t	count;
	char	*str;

	str = "0123456789abcdef";
	count = 0;
	if (i >= 16)
		count += ft_lowhexa(i / 16);
	count += ft_putchar(str[i % 16]);
	return (count);
}

int	ft_upphexa(unsigned int i)
{
	size_t	count;
	char	*str;

	str = "0123456789ABCDEF";
	count = 0;
	if (i >= 16)
		count += ft_upphexa(i / 16);
	count += ft_putchar(str[i % 16]);
	return (count);
}

int	ft_percent(void)
{
	ft_putchar('%');
	return (1);
}
