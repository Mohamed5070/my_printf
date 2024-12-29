/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:00:19 by moaatik           #+#    #+#             */
/*   Updated: 2024/12/08 15:32:13 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_and_do_part_two(const char **fmt, va_list el, int *cn, int en)
{
	if ((**fmt == 'd' || **fmt == 'i') && en)
		*cn += ft_putnbr(va_arg(el, int));
	else if (**fmt == 'c')
		*cn += ft_putchar(va_arg(el, int));
	else if (**fmt == '%')
		*cn += write(1, "%", 1);
	else if (**fmt == 'u')
		*cn += ft_put_unsigned_nbr(va_arg(el, unsigned int));
	else if (**fmt == 'x' || **fmt == 'X')
		*cn += ft_print_hexa(va_arg(el, unsigned int), **fmt);
	else if (**fmt == 'p')
	{
		*cn += ft_putstr("0x", 0);
		if (*cn == -1)
			return ;
		*cn += ft_print_hexa(va_arg(el, unsigned long), 'x');
	}
	else if (**fmt == '#')
		*cn += handle_hash(fmt, el);
	else if (**fmt == '+')
		*cn += handle_sign(fmt, el);
	else if (**fmt == '-' || (**fmt >= '0' && **fmt <= '9'))
		*cn += handle_dash_and_numbers(fmt, va_arg(el, void *));
}

static int	check_and_do(const char **format, va_list elements)
{
	int			count;
	int			enter;
	const char	*temp;

	count = 0;
	enter = 1;
	if (**format == ' ')
	{
		while (**format == ' ')
			(*format)++;
		temp = *format;
		while ((*temp >= '0' && *temp <= '9'))
			temp++;
		if (**format != '0' && (*temp == 'd' || *temp == 'i' || *temp == 's'))
		{
			count += handle_space(format, va_arg(elements, void *));
			enter = 0;
		}
	}
	if (**format == 's' && enter)
		count += ft_putstr(va_arg(elements, char *), 0);
	else
		check_and_do_part_two(format, elements, &count, enter);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	elements;
	int		count;
	int		add;

	count = 0;
	va_start(elements, format);
	while (*format)
	{
		add = 0;
		if (*format == '%' && *(++format))
		{
			if (ft_strchr("-0123456789# +cspdiuxX%", *format))
				add = check_and_do(&format, elements);
			else
				add = write(1, format, 1);
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
