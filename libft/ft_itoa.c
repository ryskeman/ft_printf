/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:51:42 by fernafer          #+#    #+#             */
/*   Updated: 2025/04/21 16:45:52 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_know_num_digits(long long n, int num)
{
	if (n > 0)
		return (ft_know_num_digits(n / 10, num + 1));
	return (num);
}

static char	*ft_handle_special_cases(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-2147483648"));
}

static char	*ft_convert_int_to_string(long long n, int is_negative, int size,
		char *s)
{
	int	total_size;

	total_size = size + is_negative;
	s[total_size] = '\0';
	while (total_size--)
	{
		s[total_size] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	int			is_negative;
	int			num_of_digits;
	char		*num_in_string;
	long long	nl;

	is_negative = 0;
	nl = n;
	if (n == 0 || n <= -2147483648)
		return (ft_handle_special_cases(n));
	if (nl < 0)
	{
		is_negative = 1;
		nl = -nl;
	}
	num_of_digits = ft_know_num_digits(nl, 0);
	if (is_negative)
		num_in_string = malloc((num_of_digits + 2) * sizeof(char));
	else
		num_in_string = malloc((num_of_digits + 1) * sizeof(char));
	if (!num_in_string)
		return (NULL);
	return (ft_convert_int_to_string(nl, is_negative, num_of_digits,
			num_in_string));
}
