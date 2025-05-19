/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:29:24 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/19 18:58:03 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *va, int *counter, int fd)
{
	char	c;

	c = (char)va_arg(*va, int);
	ft_putchar_fd_r(fd, c, counter);
	return (1);
}

int	ft_print_string(va_list *va, int *counter, int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(*va, char *);
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar_fd_r(fd, str[i], counter);
		i++;
	}
	return (i);
}

int	ft_putnbr_base_r(unsigned long long n, char *base, int *count, int fd)
{
	int	len;
	int	printed;

	len = 0;
	printed = 1;
	while (base[len])
		len++;
	if (n >= (unsigned long long)len)
	{
		printed += ft_putnbr_base_r(n / len, base, count, fd);
		ft_putchar_fd_r(fd, base[n % len], count);
	}
	else
		ft_putchar_fd_r(fd, base[n % len], count);
	return (printed);
}

int	ft_print_ptr(va_list *va, int *counter, int fd)
{
	void	*ptr;
	int		len;

	len = 0;
	ptr = va_arg(*va, void *);
	ft_putchar_fd_r(fd, '0', counter);
	ft_putchar_fd_r(fd, 'x', counter);
	len += 2;
	len += ft_putnbr_base_r((unsigned long long)ptr, "0123456789abcdef",
			counter, fd);
	return (len);
}
