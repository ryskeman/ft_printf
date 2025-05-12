/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:23:57 by fernafer          #+#    #+#             */
/*   Updated: 2025/04/21 16:51:28 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*generic_array;

	total_size = 0;
	if (nmemb == 0 || size == 0)
		total_size = 0;
	else if (nmemb > SIZE_MAX / size)
		return (NULL);
	else
		total_size = nmemb * size;
	generic_array = malloc(total_size);
	if (generic_array == 0)
		return (NULL);
	ft_memset(generic_array, 0, total_size);
	return (generic_array);
}
