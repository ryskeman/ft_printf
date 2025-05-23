/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:29:24 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/21 19:25:35 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_r(char c)
{
	if (write(1, &c, 1) == 1)
		return (1);
	return (-1);
}

int	ft_print_char(char c)
{
	return (ft_putchar_fd_r(c));
}

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar_fd_r(str[i]);
		i++;
	}
	return (i);
}
