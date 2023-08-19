/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:24:37 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/19 03:24:40 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrix_join(char **matrix, char *str)
{
	char	**result;
	int		size;
	int		index;

	if (matrix == NULL && str != NULL)
	{
		result = ft_calloc(sizeof(char *), 2);
		result[0] = ft_strdup(str);
		return (result);
	}
	else if (str == NULL)
		return (NULL);
	index = 0;
	size = ft_matrix_strlen(matrix);
	result = ft_calloc(sizeof(char *), size + 2);
	while (index < size)
	{
		result[index] = ft_strdup(matrix[index]);
		index++;
	}
	result[index] = ft_strdup(str);
	ft_matrix_strdel(matrix);
	return (result);
}
