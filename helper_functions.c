/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:08:28 by moaatik           #+#    #+#             */
/*   Updated: 2024/12/07 18:10:05 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

int	ft_atoi(const char **str)
{
	long	result;

	result = 0;
	while (**str == ' ')
		(*str)++;
	while (**str == '-' || **str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	while (**str == ' ')
		(*str)++;
	return (result);
}
