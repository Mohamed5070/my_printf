/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_flags_functions_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:49:44 by moaatik           #+#    #+#             */
/*   Updated: 2024/12/08 15:33:50 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned_nbr_dash(unsigned int nb, const char **format, int *sp)
{
	int	count;

	*sp = ft_atoi(format) - ft_count(nb);
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

int	ft_putchar_dash(int c, const char **format, int *number_of_spaces)
{
	int	count;

	*number_of_spaces = ft_atoi(format) - 1;
	count = ft_putchar(c);
	return (count);
}

int	ft_putstr_dash(char *str, const char **format, int *number_of_spaces)
{
	int	count;

	*number_of_spaces = ft_atoi(format) - ft_strlen(str);
	count = ft_putstr(str, 0);
	return (count);
}

int	ft_hx_dash(unsigned long nb, const char **format, char c, int *spaces)
{
	int			count;
	int			n;
	const char	*temp;

	count = 0;
	temp = *format;
	n = ft_atoi(format);
	while (*temp == 'p' || *temp == ' ' || (*temp >= '0' && *temp <= '9'))
		temp--;
	temp++;
	if (c == 'p' && *temp != '0' && *temp != ' ')
	{
		count = ft_putstr("0x", 0);
		if (count == -1)
			return (-1);
	}
	*spaces = n - (count_hexa(nb) + count);
	count += ft_print_hexa(nb, c);
	if (n < count)
		*spaces = 0;
	return (count);
}
