/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:55:38 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/24 16:54:11 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int is_allocated)
{
	size_t	i;

	if (!s)
		return (ft_putstr("(null)", 0));
	i = 0;
	while (s[i])
	{
		if (write (1, &s[i], 1) == -1)
		{
			if (is_allocated)
				free(s);
			return (-1);
		}
		i++;
	}
	if (is_allocated)
		free(s);
	return (i);
}
