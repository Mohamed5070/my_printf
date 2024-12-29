/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:55:38 by moaatik           #+#    #+#             */
/*   Updated: 2024/12/06 15:55:31 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

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
