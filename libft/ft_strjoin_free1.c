/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:51:15 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/22 02:51:18 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free1(char *s1, char const *s2, size_t size2)
{
	unsigned int	size;
	unsigned int	size1;
	char			*new;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size = size1 + size2 + 1;
	new = (char *)ft_calloc(sizeof(char), size);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, size1 + 1);
	ft_strlcpy(new + size1, s2, size2 + 1);
	ft_strdel(&s1);
	return (new);
}
