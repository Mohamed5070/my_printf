/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:53:52 by moaatik           #+#    #+#             */
/*   Updated: 2024/12/07 20:20:37 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_number(const char *temp, const char **format, void *ptr)
{
	int	n;

	n = 0;
	if (*temp == 'd' || *temp == 'i' )
		n = ft_atoi(format) - ft_count((int)ptr);
	else if (*temp == 'u')
		n = ft_atoi(format) - ft_count((unsigned int)ptr);
	else if (*temp == 'x' || *temp == 'X')
		n = ft_atoi(format) - count_hexa((unsigned int)ptr);
	else if (*temp == 'c')
		n = ft_atoi(format) - 1;
	else if (*temp == 's')
		n = ft_atoi(format) - ft_strlen((char *)ptr);
	else if (*temp == 'p')
		n = ft_atoi(format) - (count_hexa((unsigned long)ptr) + 2);
	return (n);
}

int	ft_count(long i)
{
	int	count;

	if (i == 0)
		return (1);
	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

int	count_hexa(long nb)
{
	int	count;

	count = 1;
	while (nb >= 16)
	{
		nb /= 16;
		count++;
	}
	return (count);
}
