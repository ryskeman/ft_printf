/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:21:44 by fernafer          #+#    #+#             */
/*   Updated: 2025/04/21 16:17:12 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_know_words(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

static void	*ft_free_memory(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

static char	**ft_fill_up_matrix(const char *s, char **matrix, char c)
{
	int	i;
	int	start;
	int	idx;

	i = 0;
	start = -1;
	idx = 0;
	while (s[i])
	{
		if (s[i] != c && start == -1)
			start = i;
		if (start != -1 && (s[i + 1] == '\0' || s[i] == c))
		{
			matrix[idx] = ft_substr(s, start, i - start + (s[i] != c));
			if (!matrix[idx])
				return (NULL);
			idx++;
			start = -1;
		}
		i++;
	}
	matrix[idx] = NULL;
	return (matrix);
}

static char	**ft_handle_special_cases(void)
{
	char	**matrix;

	matrix = malloc(sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix[0] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	int		num_substrings;
	char	**matrix;

	if (!s)
		return (NULL);
	num_substrings = ft_know_words(s, c);
	if (num_substrings == 0)
		return (ft_handle_special_cases());
	matrix = malloc((num_substrings + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	if (!ft_fill_up_matrix(s, matrix, c))
		return (ft_free_memory(matrix));
	return (matrix);
}
