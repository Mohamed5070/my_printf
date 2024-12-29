/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_flags_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:13:28 by moaatik           #+#    #+#             */
/*   Updated: 2024/12/08 15:34:58 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hash(const char **format, va_list elements)
{
	unsigned int	nb;
	int				count;

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

int	handle_sign(const char **format, va_list elements)
{
	int	count;
	int	nb;

	(*format)++;
	while (**format == ' ')
		(*format)++;
	count = 0;
	nb = va_arg(elements, int);
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

int	handle_space_part2(int nb, char *ptr, const char **format, int spaces)
{
	int	count;
	int	add;

	add = 0;
	count = 0;
	if ((**format == 'd' || **format == 'i') \
	&& spaces < ft_count(nb) && nb >= 0)
		spaces = 1;
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

int	handle_space(const char **format, void *p)
{
	char	*ptr;
	int		nb;
	int		spaces;
	int		flag;

	while (**format == ' ')
		(*format)++;
	flag = 0;
	ptr = (char *)p;
	nb = (int)p;
	if (**format >= '0' && **format <= '9')
		flag = 1;
	spaces = ft_atoi(format);
	if (**format == 's')
		spaces -= ft_strlen(ptr);
	else if (**format == 'd' || **format == 'i')
	{
		if (flag)
			spaces -= ft_count(nb);
		else if (!flag && nb >= 0)
			spaces = 1;
		else
			spaces = 0;
	}
	return (handle_space_part2(nb, ptr, format, spaces));
}
