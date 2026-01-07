/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltourbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:55:16 by ltourbe           #+#    #+#             */
/*   Updated: 2025/11/27 16:54:40 by ltourbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printf2(char c, va_list args);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_hexaddress(void *ptr);
int	ft_putnbr(int i);
int	ft_unsigned_putnbr(unsigned int i);
int	ft_lowhexa(unsigned long i);
int	ft_upphexa(unsigned int i);
int	ft_percent(void);

#endif
