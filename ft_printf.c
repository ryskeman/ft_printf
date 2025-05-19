/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:40:18 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/19 19:00:20 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_r(int fd, char c, int *count)
{
	if (write(fd, &c, 1) == 1)
	{
		(*count)++;
		return (1);
	}
	return (-1);
}

const char	*ft_scan(const char *str, va_list *va, int *counter, int fd)
{
	str++;
	if (*str == 'c')
		ft_print_char(*va, counter, fd);
	else if (*str == 's')
		ft_print_string(*va, counter, fd);
	else if (*str == 'p')
		ft_print_ptr(*va, counter, fd);
	else if (*str == 'i' || *str == 'd')
		ft_print_int(*va, counter, fd);
	else if (*str == 'u')
		ft_print_uint(*va, counter, fd);
	else if (*str == 'x')
		ft_print_hex(*va, 0, counter, fd);
	else if (*str == 'X')
		ft_print_hex(*va, 1, counter, fd);
	else if (*str == '%')
		ft_print_percent(counter, fd);
	else if (*str != '\0')
		ft_print_invalid(*str, counter, fd);
	else
		return (NULL);
	return (++str);
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
			str = ft_scan(str, &vargs, &printed, 1);
			if (!str)
			{
				va_end(vargs);
				return (-1);
			}
		}
		else
			ft_putchar_fd_r(1, *str, &printed);
		str++;
	}
	va_end(vargs);
	return (printed);
}
