/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 02:33:19 by aminoru-          #+#    #+#             */
/*   Updated: 2023/06/15 20:52:12 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
* 	The strncmp() function compares not more than n characters. Because 
*	strncmp() is designed for comparing strings rather than binary data, 
*	characters that appear after a `\0' character are not compared.
*	PARAMETERS
*	#1. The first str to compare.
*	#2. The second str to compare.
*	#3. The number of bytes to compare the two strings.
*	RETURN VALUES
*	The strncmp() function returns an integer greater than, equal to, or less 
*	than 0, according as the string s1 is greater than, equal to, or less than 
*	the string s2.  The comparison is done using unsigned characters, so that 
*	`\200' is greater than `\0'.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n -1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}