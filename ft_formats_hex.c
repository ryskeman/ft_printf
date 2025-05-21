/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:35:43 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/21 20:09:29 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_putchar_fd_r('(');
		count += ft_putchar_fd_r('n');
		count += ft_putchar_fd_r('i');
		count += ft_putchar_fd_r('l');
		count += ft_putchar_fd_r(')');
		return (count);
	}
	count += ft_putchar_fd_r('0');
	count += ft_putchar_fd_r('x');
	count += ft_putnbr_base_r((unsigned long long)ptr, "0123456789abcdef");
	return (count);
}

static int	ft_get_hex_char(unsigned int digit, int upper)
{
	if (digit < 10)
		return (digit + '0');
	if (upper)
		return (digit - 10 + 'A');
	return (digit - 10 + 'a');
}

int	ft_print_hex(unsigned int num, int upper)
{
	int				count;
	unsigned int	digit;

	count = 0;
	if (num >= 16)
		count += ft_print_hex(num / 16, upper);
	digit = num % 16;
	count += ft_putchar_fd_r(ft_get_hex_char(digit, upper));
	return (count);
}
