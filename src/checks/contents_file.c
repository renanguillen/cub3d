/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:13:14 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/23 00:13:18 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_position_map(char **file)
{
	int	index;
	int	map;

	index = 0;
	map = 0;
	while (file[index] != NULL)
	{
		if (is_line_map(file[index]))
			map = 1;
		else if (map == 1)
			return (1);
		index++;
	}
	return (0);
}

static int	check_contents(char **file, char *key)
{
	int	index;
	int	find;
	int	size;
	int	count;

	index = 0;
	find = 0;
	size = ft_strlen(key);
	while (file[index] != NULL)
	{
		count = 0;
		if (ft_strlen(file[index]) > 0)
		{
			while (key[count] == file[index][count] && count < size)
				count++;
			if (count == size)
				find++;
		}
		index++;
	}
	if (find == 1)
		return (0);
	return (1);
}

int	check_integrity_map(char **file)
{
	int	index;
	int	map_active;
	int	map_break;
	int	line_map;

	index = 0;
	map_active = 0;
	map_break = 0;
	while (file[index] != NULL)
	{
		line_map = is_line_map(file[index]);
		if (map_active == 0 && line_map == 1)
			map_active = 1;
		else if (map_active == 1 && line_map == 0)
			map_break = 1;
		else if (map_break == 1 && line_map == 1)
			return (1);
		index++;
	}
	if (map_active == 1)
		return (0);
	return (1);
}

int	check_contents_file(char **file)
{
	int	error;

	error = 0;
	error += check_contents(file, "NO ");
	error += check_contents(file, "SO ");
	error += check_contents(file, "WE ");
	error += check_contents(file, "EA ");
	error += check_contents(file, "C ");
	error += check_contents(file, "F ");
	if (error != 0)
	{
		printf(ERROR_MAP_ELEMENT);
		return (1);
	}
	if (check_integrity_map(file))
	{
		printf(ERROR_WRONG_LINE_MAP);
		return (1);
	}	
	if (check_position_map(file))
	{
		printf(ERROR_MAP_NOT_LAST);
		return (1);
	}
	return (0);
}