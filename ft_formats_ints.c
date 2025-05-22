/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats_ints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:35:19 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/22 16:53:12 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		count += ft_putchar_fd_r('-');
		num = -num;
	}
	if (num >= 10)
		count += ft_print_int(num / 10);
	count += ft_putchar_fd_r((num % 10) + '0');
	return (count);
}

int	ft_print_uint(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_print_uint(num / 10);
	count += ft_putchar_fd_r((num % 10) + '0');
	return (count);
}
