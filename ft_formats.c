/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:29:24 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/16 14:09:58 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *va, int *counter)
{
	char	c;

	c = (char)va_arg(*va, int);
	ft_putchar_fd_r(STDOUT_FILENO, c, counter);
	return (1);
}

int	ft_print_string(va_list *va, int *counter)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(*va, char *);
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar_fd_r(STDOUT_FILENO, str[i], counter);
		i++;
	}
	return (i);
}

ft_print_ptr(va_list *va,int *counter)
{

}
