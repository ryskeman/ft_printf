/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:29:24 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/20 18:50:15 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	ft_putchar_fd_r(c);
	return (1);
}

int	ft_print_string(char *str)
{
	int		i;

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
