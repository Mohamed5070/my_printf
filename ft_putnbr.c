/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:53:07 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/24 19:36:26 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	char	*result;
	int		i;

	i = ft_count(nb);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (-1);
	result[i] = 0;
	i--;
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		result[0] = '-';
	}
	while (nb > 0)
	{
		result[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ft_putstr(result, 1));
}
