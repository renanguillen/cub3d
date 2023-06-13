/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:23:17 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/13 09:25:31 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
* Allocates memory for a new string and copies the string passed as argument
* into it.

* Returns the new string.
*/
char	*ft_strdup(char *tobecopied)
{
	char	*newstring;
	int		i;

	if (!tobecopied)
		return (NULL);
	newstring = (char *) malloc(ft_strlen(tobecopied) + 1);
	if (!newstring)
		return (NULL);
	i = 0;
	while (tobecopied[i])
	{
		newstring[i] = tobecopied[i];
		i++;
	}
	newstring[i] = 0;
	return (newstring);
}
