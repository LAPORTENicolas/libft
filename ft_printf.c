/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:50:39 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/15 01:50:39 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_format_p(void *ad, int fd, int suffix)
{
	if ((long long unsigned)ad != 0)
		return (ft_puthex_fd((long long unsigned)ad, fd, suffix));
	return (ft_putstr_fd("(nil)", fd));
}

int	ft_parse(const char *format, unsigned int len, va_list args)
{
	int	size;

	size = 0;
	if (format[len] == 'c')
		size += ft_putchar_fd(va_arg(args, int), 1);
	else if (format[len] == 's')
		size += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format[len] == 'p')
		size += ft_format_p(va_arg(args, void *), 1, 1);
	else if (format[len] == 'd' || format[len] == 'i')
		size += ft_putnbr_fd(va_arg(args, int), 1);
	else if (format[len] == 'u')
		size += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (format[len] == 'x')
		size += ft_printhex2(va_arg(args, unsigned int), 1, "0123456789abcdef");
	else if (format[len] == 'X')
		size += ft_printhex2(va_arg(args, unsigned int), 1, "0123456789ABCDEF");
	else if (format[len] == 'f')
		size += ft_printfloat_fd(va_arg(args, double), 1);
	else if (format[len] == '%')
		size += ft_putchar_fd('%', 1);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list				args;
	unsigned int		len;
	unsigned int		lenmax;
	unsigned int		size;

	va_start(args, format);
	va_end(args);
	len = 0;
	lenmax = ft_strlen(format);
	size = 0;
	while (len < lenmax)
	{
		if (format[len] != '%')
			size += ft_putchar_fd(format[len], 1);
		else
			size += ft_parse(format, ++len, args);
		len++;
	}
	return (size);
}
