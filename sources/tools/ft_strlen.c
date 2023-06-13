/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:30:40 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/13 08:40:59 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Takes a string as argument to calculate its length.

* Returns the length of the string.
*/
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
