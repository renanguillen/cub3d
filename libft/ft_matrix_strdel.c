/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_strdel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:24:43 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/19 03:24:45 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_strdel(char **matrix)
{
	int	index;
	int	size;

	index = 0;
	if (matrix == NULL)
		return ;
	size = ft_matrix_strlen(matrix);
	while (index < size)
	{
		ft_strdel(&matrix[index]);
		index++;
	}
	free(matrix);
}
