/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:55:02 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/24 17:04:07 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr(unsigned int nb)
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
	while (nb > 0)
	{
		result[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ft_putstr(result, 1));
}
