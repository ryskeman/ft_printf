/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:34:10 by fernafer          #+#    #+#             */
/*   Updated: 2025/04/21 16:14:03 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	size_t	s_size;

	s_size = ft_strlen(s);
	s_copy = malloc(s_size + 1);
	if (s_copy == NULL)
		return (NULL);
	ft_memcpy(s_copy, s, s_size + 1);
	return (s_copy);
}
