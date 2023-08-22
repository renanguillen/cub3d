/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linebreak.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:54:00 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/22 02:54:03 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_linebreak(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}
