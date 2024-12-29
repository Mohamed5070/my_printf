/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:59:10 by moaatik           #+#    #+#             */
/*   Updated: 2024/12/08 15:33:08 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		handle_hash(const char **format, va_list elements);
int		handle_sign(const char **format, va_list elements);
int		handle_space(const char **format, void *p);
int		handle_dash_and_numbers(const char **format, void *ptr);
int		put_unsigned_nbr_dash(unsigned int nb, const char **format, int *sp);
int		put_nbr_dash(int nb, const char **format, int *number_of_spaces);
int		ft_putchar_dash(int c, const char **format, int *number_of_spaces);
int		ft_putstr_dash(char *str, const char **format, int *number_of_spaces);
int		ft_hx_dash(unsigned long nb, const char **format, char c, int *spaces);
int		ft_print_hexa(unsigned long nb, char X);
int		ft_put_unsigned_nbr(unsigned int nb);
int		ft_putchar(int c);
int		ft_putnbr(long nb);
int		ft_putstr(char *s, int is_allocated);
int		ft_count(long i);
int		ft_strchr(const char *s, int c);
int		ft_atoi(const char **str);
size_t	ft_strlen(const char *s);
int		count_hexa(long nb);
int		count_number(const char *temp, const char **format, void *ptr);

#endif