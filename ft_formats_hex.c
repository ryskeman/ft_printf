/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:35:43 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/20 19:39:42 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_r(unsigned long long n, char *base)
{
	int	len;
	int	printed;

	len = 0;
	printed = 1;
	while (base[len])
		len++;
	if (n >= (unsigned long long)len)
	{
		printed += ft_putnbr_base_r(n / len, base);
		ft_putchar_fd_r(base[n % len]);
	}
	else
		ft_putchar_fd_r(base[n % len]);
	return (printed);
}

int	ft_print_ptr(void *ptr)
{
	int		len;

	len = 0;
	write (1, "0x", 2);
	len += 2;
	len += ft_putnbr_base_r((unsigned long long)ptr, "0123456789abcdef");
	return (len);
}
