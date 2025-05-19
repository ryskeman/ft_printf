/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:52:27 by fernafer          #+#    #+#             */
/*   Updated: 2025/05/19 18:55:26 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *format, ...);
int				ft_putchar_fd_r(int fd, char c, int *count);
int				ft_print_char(va_list *va, int *counter, int fd);
int				ft_print_string(va_list *va, int *counter, int fd);
const char		*ft_scan(const char *str, va_list *va, int *counter, int fd);

#endif
