/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:29:02 by fernafer          #+#    #+#             */
/*   Updated: 2025/04/21 16:17:39 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trimmed;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	str_trimmed = malloc((end - start + 2) * sizeof(char));
	if (!str_trimmed)
		return (NULL);
	i = 0;
	while (start <= end)
		str_trimmed[i++] = s1[start++];
	str_trimmed[i] = '\0';
	return (str_trimmed);
}
