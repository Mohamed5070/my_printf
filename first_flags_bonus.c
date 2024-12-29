/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:44:37 by moaatik           #+#    #+#             */
/*   Updated: 2024/12/08 17:54:55 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_zero(const char **format, const char *temp, int *enter, void *ptr)
{
	int	n;
	int	count;

	count = 0;
	(*format)++;
	n = count_number(temp, format, ptr);
	if ((int)ptr < 0 && (*temp == 'd' || *temp == 'i'))
	{
		*enter = 2;
		count += write(1, "-", 1);
	}
	if (*temp == 'p')
	{
		count += ft_putstr("0x", 0);
		if (count == -1)
			return (-1);
	}
	while (n > 0)
	{
		count += write(1, "0", 1);
		n--;
	}
	return (count);
}

int	handle_dash_part2(const char **format, const char *temp, void *ptr, int *sp)
{
	int	count;

	count = 0;
	if (*temp == 's')
		count += ft_putstr_dash((char *)ptr, format, sp);
	if (*temp == 'c')
		count += ft_putchar_dash((int)ptr, format, sp);
	if (*temp == 'p')
		count += ft_hx_dash((unsigned long)ptr, format, *temp, sp);
	else if (*temp == 'u')
		count += put_unsigned_nbr_dash((unsigned int)ptr, format, sp);
	else if (*temp == 'x' || *temp == 'X')
		count += ft_hx_dash((unsigned int)ptr, format, *temp, sp);
	return (count);
}

int	handle_dash(const char **format, int enter, void *ptr)
{
	int			nb;
	int			count;
	int			spaces;
	const char	*temp;

	count = 0;
	spaces = 0;
	temp = *format;
	while ((*temp >= '0' && *temp <= '9') || *temp == ' ')
		temp++;
	if (*temp == 'd' || *temp == 'i')
	{
		nb = (int)ptr;
		if (nb == -2147483648 && enter == 2)
			return (ft_putstr("2147483648", 0));
		if (enter == 2)
			nb = -nb;
		count += put_nbr_dash(nb, format, &spaces);
	}
	count += handle_dash_part2(format, temp, ptr, &spaces);
	if (count == -1)
		return (-1);
	while (spaces-- > 0 && !enter)
		count += write(1, " ", 1);
	return (count);
}

int	handle_number(const char **format, const char *temp, int *enter, void *ptr)
{
	int	n;
	int	count;
	int	add;

	count = 0;
	n = count_number(temp, format, ptr);
	*enter = 1;
	while (n > 0)
	{
		add = write(1, " ", 1);
		if (add == -1)
			return (-1);
		count += add;
		n--;
	}
	return (count);
}

int	handle_dash_and_numbers(const char **fmt, void *ptr)
{
	const char	*temp;
	int			count;
	int			enter;

	enter = 0;
	count = 0;
	if (**fmt >= '0' && **fmt <= '9')
	{
		temp = *fmt;
		while ((*temp >= '0' && *temp <= '9') || *temp == ' ')
			temp++;
		if (**fmt == '0')
		{
			enter = 1;
			count += handle_zero(fmt, temp, &enter, ptr);
		}
		else if ((**fmt >= '1' && **fmt <= '9'))
			count += handle_number(fmt, temp, &enter, ptr);
	}
	if (**fmt == '-')
		(*fmt)++;
	count += handle_dash(fmt, enter, ptr);
	return (count);
}
