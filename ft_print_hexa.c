/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:56:22 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/26 17:51:11 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long nb, char upper_or_lower)
{
	int		i;
	int		j;
	char	*s;
	char	result[20];
	char	temp[20];

	i = 0;
	j = 0;
	s = "0123456789abcdef";
	if (nb == 0)
		return (ft_putstr("0", 0));
	while (nb > 0)
	{
		if (upper_or_lower == 'X' && (s[nb % 16] >= 'a' && s[nb % 16] <= 'f'))
			temp[i] = s[nb % 16] - 32;
		else
			temp[i] = s[nb % 16];
		i++;
		nb /= 16;
	}
	temp[i--] = 0;
	while (i >= 0)
		result[j++] = temp[i--];
	result[j] = 0;
	return (ft_putstr(result, 0));
}
