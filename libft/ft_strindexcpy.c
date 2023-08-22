/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindexcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:51:07 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/22 02:51:11 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strindexcpy(char **save, char *str, size_t index)
{
	size_t			count;
	char			*dst;
	size_t			size;

	count = 0;
	size = ft_strlen(str);
	dst = (char *)ft_calloc(sizeof(char), (size - (index)) + 1);
	while (count < size && index < size)
	{
		dst[count] = str[index];
		index++;
		count++;
	}
	dst[count] = '\0';
	*save = dst;
	return (dst);
}
