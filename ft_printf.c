/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:59:08 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/25 14:08:24 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_and_do(const char *format, va_list elements)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(elements, int));
	else if (*format == '%')
		count += write(1, "%%", 1);
	else if (*format == 's')
		count += ft_putstr(va_arg(elements, char *), 0);
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(elements, int));
	else if (*format == 'u')
		count += ft_put_unsigned_nbr(va_arg(elements, unsigned int));
	else if (*format == 'x' || *format == 'X')
		count += ft_print_hexa(va_arg(elements, unsigned int), *format);
	else if (*format == 'p')
	{
		count += ft_putstr("0x", 0);
		if (count == -1)
			return (-1);
		count += ft_print_hexa(va_arg(elements, unsigned long), 'x');
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	elements;
	int		count;
	int		add;

	count = 0;
	add = 0;
	va_start(elements, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (ft_strchr("cspdiuxX%%", *format))
				add = check_and_do(format, elements);
		}
		else
			add = write(1, format, 1);
		if (add == -1)
			return (-1);
		count += add;
		format++;
	}
	va_end(elements);
	return (count);
}
