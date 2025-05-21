/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:52:27 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/21 19:59:21 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd_r(char c);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_ptr(void *ptr);
int	ft_putnbr_base_r(unsigned long long n, char *base);
int	ft_print_int(int num);
int	ft_print_uint(unsigned int num);
int	ft_print_hex(unsigned int num, int upper);
int	ft_print_percent(void);
int	ft_scan(const char *str, va_list va);

#endif
