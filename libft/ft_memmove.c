/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:16:21 by fernafer          #+#    #+#             */
/*   Updated: 2025/04/21 16:03:11 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		i = 0;
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
