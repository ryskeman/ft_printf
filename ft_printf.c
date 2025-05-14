/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:40:18 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/14 13:03:18 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		vargs;
	int			print_chars;

	if (!str || *str == '\0')
		return (0);
	print_chars = 0;
	va_start(vargs, str);
	while (*str)
	{
		if (*str == '%')
		{
			str = ft_scan(str, &vargs, &print_chars);
			if (!str)
			{
				va_end(vargs);
				return (-1);
			}
		}
		else
			ft_putchar_r(*str, &print_chars);
		str++;
	}
	va_end(vargs);
	return (print_chars);
}
