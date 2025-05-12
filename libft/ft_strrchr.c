/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:30:45 by fernafer          #+#    #+#             */
/*   Updated: 2025/04/21 16:26:04 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[s_len]);
	while (s_len--)
	{
		if (s[s_len] == (unsigned char)c)
			return ((char *)&s[s_len]);
	}
	return (0);
}
