/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:24:56 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/19 03:24:59 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrix_strlen(char **matrix)
{
	int	len;

	len = 0;
	if (matrix == NULL)
		return (-1);
	while (matrix[len] != 0)
		len++;
	return (len);
}
