/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:24:50 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/19 03:24:53 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrix_strdup(char **matrix)
{
	char	**result;
	int		size;
	int		index;

	index = 0;
	if (matrix == NULL)
		return (NULL);
	size = ft_matrix_strlen(matrix);
	result = ft_calloc(sizeof(char *), size);
	while (index < size)
	{
		result[index] = ft_strdup(matrix[index]);
		index++;
	}
	return (result);
}
