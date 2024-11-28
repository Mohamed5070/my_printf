/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:59:10 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/25 13:49:50 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_print_hexa(unsigned long nb, char X);
int		ft_put_unsigned_nbr(unsigned int nb);
int		ft_putchar(int c);
int		ft_putnbr(long nb);
int		ft_putstr(char *s, int is_allocated);
int		ft_count(long i);
char	*ft_strchr(const char *s, int c);

#endif