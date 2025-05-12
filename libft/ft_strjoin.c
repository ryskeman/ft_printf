/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:00:29 by fernafer          #+#    #+#             */
/*   Updated: 2025/04/21 16:16:13 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_generate_space(size_t len)
{
	return ((char *)malloc(len * sizeof(char)));
}

static char	*ft_join_string(char const *s1, char const *s2, size_t i, size_t j)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_generate_space(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			new_str[i] = s1[i];
		else
		{
			new_str[i] = s2[j];
			j++;
		}
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s2_copy;
	char	*s1_copy;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
	{
		s2_copy = ft_generate_space(ft_strlen(s2) + 1);
		if (!s2_copy)
			return (NULL);
		return (ft_memcpy(s2_copy, s2, ft_strlen(s2) + 1));
	}
	else if (!s2)
	{
		s1_copy = ft_generate_space(ft_strlen(s1) + 1);
		if (!s1_copy)
			return (NULL);
		return (ft_memcpy(s1_copy, s1, ft_strlen(s1) + 1));
	}
	else
		return (ft_join_string(s1, s2, 0, 0));
}
