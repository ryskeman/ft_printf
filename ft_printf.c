/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:40:18 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/21 18:19:29 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	return (ft_putchar_fd_r('%'));
}

int	ft_scan(const char *str, va_list va)
{
	int	count;

	str++;
	count = 0;
	if (*str == 'c')
		count += ft_print_char(va_arg(va, int));
	else if (*str == 's')
		count += ft_print_string(va_arg(va, char *));
	else if (*str == 'p')
		count += ft_print_ptr(va_arg(va, void *));
	else if (*str == 'i' || *str == 'd')
		count += ft_print_int(va_arg(va, int));
	else if (*str == 'u')
		count += ft_print_uint(va_arg(va, unsigned int));
	else if (*str == 'x')
		count += ft_print_hex(va_arg(va, unsigned int), 0);
	else if (*str == 'X')
		count += ft_print_hex(va_arg(va, unsigned int), 1);
	else if (*str == '%')
		count += ft_print_percent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	vargs;
	int		printed;

	printed = 0;
	if (!str)
		return (-1);
	va_start(vargs, str);
	while (*str)
	{
		if (*str == '%')
		{
			printed += ft_scan(str, vargs);
			if (!str)
			{
				va_end(vargs);
				return (-1);
			}
		}
		else
			ft_putchar_fd_r(*str);
		str++;
	}
	va_end(vargs);
	return (printed);
}
