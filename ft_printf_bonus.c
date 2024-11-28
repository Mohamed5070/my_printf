/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:27:43 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/28 13:41:08 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

 int	put_unsigned_nbr_dash(unsigned int nb, const char **format, int *number_of_spaces)
 {
	int	count;

	*number_of_spaces = ft_atoi(format) - ft_count(nb);
	count = ft_put_unsigned_nbr(nb);
	return (count);
 }
 
int	put_nbr_dash(int nb, const char **format, int *number_of_spaces)
{
	int	count;

	*number_of_spaces = ft_atoi(format) - ft_count(nb);
	count = ft_putnbr(nb);
	return (count);
}

int ft_putchar_dash(int c, const char **format,int *number_of_spaces)
{
	int	count;

	*number_of_spaces = ft_atoi(format) - 1;
	count = ft_putchar(c);
	return (count);
}

int	ft_putstr_dash(char *str, const char **format,int *number_of_spaces)
{
	int	count;

	*number_of_spaces = ft_atoi(format) - ft_strlen(str);
	count = ft_putstr(str, 0);
	return (count);
}

int	ft_print_hexa_dash(unsigned long nb, const char **format, char c, int *number_of_spaces)
{
	int	count;
	int	n;

	count = 0;
	n = ft_atoi(format);
	if (c == 'p')
	{
		count = ft_putstr("0x", 0);
		if (count == -1)
			return (-1);
	}
	*number_of_spaces = n - (count_hexa(nb) + count);
	count += ft_print_hexa(nb, c);
	if (n < count)
		*number_of_spaces = 0;
	return (count);
}

int	handle_dash_and_numbers(const char **format, void *ptr)
{
	const char	*temp;
	int	count;
	int	number_of_spaces;
	int	add;
	int	enter;
	int	n;

	enter = 0;
	count = 0;
	n = 0;
	if (**format >= '0' && **format <= '9')
	{
		temp = *format;
		while (*temp >= '0' && *temp <= '9')
			temp++;
		if (**format == '0')
		{
			(*format)++;
			if (*temp == 'd' || *temp == 'i' )
				n = ft_atoi(format) - ft_count((int)ptr);
			else if (*temp == 'u')
				n = ft_atoi(format) - ft_count((unsigned int)ptr);
			else if (*temp == 'x' || *temp == 'X')
				n = ft_atoi(format) - count_hexa((unsigned int)ptr);
			enter = 1;
			if ((int)ptr < 0 && !(*temp == 'u' || *temp == 'x' || *temp == 'X'))
			{
				enter = 2;
				add = write(1, "-", 1);
				if (add == -1)
					return (-1);
				count += add;
			}
			while (n > 0)
			{
				add = write(1, "0", 1);
				if (add == -1)
					return (-1);
				count += add;
				n--;
			}
		}
	}
	if (**format == '-')
		(*format)++;
	temp = *format;
	while (*temp >= '0' && *temp <= '9')
		temp++;
	if (*temp == 'c')
		count += ft_putchar_dash((int)ptr, format, &number_of_spaces);
	else if (*temp == 's')
		count += ft_putstr_dash((char *)ptr, format, &number_of_spaces);
	else if (*temp == 'd' || *temp == 'i')
	{
		add = (int)ptr;
		if (add == -2147483648 && enter == 2)
			return (count + ft_putstr("2147483648", 0));
		if (enter == 2)
			add = -add;
		count += put_nbr_dash(add, format, &number_of_spaces);
	}
	else if (*temp == 'p')
		count += ft_print_hexa_dash((unsigned long)ptr, format, 'p', &number_of_spaces);
	else if (*temp == 'u')
		count += put_unsigned_nbr_dash((unsigned int)ptr, format, &number_of_spaces);
	else if (*temp == 'x' || *temp == 'X')
		count += ft_print_hexa_dash((unsigned int)ptr, format, *temp, &number_of_spaces);
	if (count == -1)
		return (-1);
	while (number_of_spaces > 0 && !enter)
	{
		add = write(1, " ", 1);
		if (add == -1)
			return (-1);
		count += add;
		number_of_spaces--;
	}
	return (count);
}

static int	handle_space(const char **format, void *p)
{
	int	count;
	int	nb;
	char	*ptr;
	int	spaces;
	int add;

	while (**format == ' ')
		(*format)++;
	count = 0;
	add = 0;
	ptr = (char *)p;
	nb = (int)p;
	if (**format >= '0' && **format <= '9')
		add = 1;
	spaces = ft_atoi(format);
	if (**format == 's')
		spaces -= ft_strlen(ptr);
	else if (**format == 'd' || **format == 'i')
	{
		if (add)
			spaces -= ft_count(nb);
		else if (!add && nb >= 0)
			spaces = 1;
		else
			spaces = 0;
	}
	while (spaces > 0)
	{
		add = write(1, " ", 1);
		if (add == -1)
			return (-1);
		count += add;
		spaces--;
	}
	if (**format == 's')
		count += ft_putstr(ptr, 0);
	if (**format == 'd' || **format == 'i')
		count += ft_putnbr(nb);
	return (count);
}

static int	handle_sign(const char **format, va_list elements)
{
	int	count;
	int	nb;

	count = 0;
	nb = va_arg(elements, int);
	(*format)++;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648", 0));
	if (nb >= 0)
		count += ft_putchar('+');
	else
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (count == -1)
		return (-1);
	count += ft_putnbr(nb);
	return (count);
}

static int	handle_hash(const char **format, va_list elements)
{
	int		count;
	unsigned int	nb;

	(*format)++;
	while (**format == ' ')
		(*format)++;
	count = 0;
	nb = va_arg(elements, unsigned int);
	if (**format == 'x' || **format == 'X')
	{
		if (**format == 'x' && nb != 0)
			count += ft_putstr("0x", 0);
		else if (**format == 'X' && nb != 0)
			count += ft_putstr("0X", 0);
		if (count == -1)
			return (-1);
		count += ft_print_hexa(nb, **format);
	}
	return (count);
}

static int	check_and_do(const char **format, va_list elements)
{
	int	count;

	count = 0;
	
	if (**format == ' ')
		count += handle_space(format, va_arg(elements, void *));
	else if (**format == 'c')
		count += ft_putchar(va_arg(elements, int));
	else if (**format == '%')
		count += write(1, "%%", 1);
	else if (**format == 's')
		count += ft_putstr(va_arg(elements, char *), 0);
	else if (**format == 'd' || **format == 'i')
		count += ft_putnbr(va_arg(elements, int));
	else if (**format == 'u')
		count += ft_put_unsigned_nbr(va_arg(elements, unsigned int));
	else if (**format == '#')
		count += handle_hash(format, elements);
	else if (**format == '+')
		count += handle_sign(format, elements);
	else if (**format == '-' || (**format >= '0' && **format <= '9'))
		count += handle_dash_and_numbers(format, va_arg(elements, void *));
	else if (**format == 'x' || **format == 'X')
		count += ft_print_hexa(va_arg(elements, unsigned int), **format);
	else if (**format == 'p')
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
	add =0;
	va_start(elements, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (ft_strchr("-0123456789# +cspdiuxX%%", *format))
				add = check_and_do(&format, elements);
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
