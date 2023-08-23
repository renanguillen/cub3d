/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail_map_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:13:24 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/19 03:13:25 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_walls_aux(char **map)
{
	int	index;
	int	len;

	index = -1;
	while (map[++index])
	{
		len = ft_strlen(map[index]);
		if (ft_strchr("NSEW0", map[index][0])
				|| ft_strchr("NSEW0", map[index][len - 1]))
			return (1);
	}
	return (0);
}

int	check_walls(t_map *map)
{
	int	index;
	int	len;
	int	size_map;

	index = -1;
	size_map = ft_matrix_strlen(map->map_matrix);
	if (check_walls_aux(map->map_matrix))
		return (1);
	len = ft_strlen(map->map_matrix[0]);
	while (++index < len)
		if (ft_strchr("NSEW0", map->map_matrix[0][index]))
			return (1);
	len = ft_strlen(map->map_matrix[size_map - 1]);
	while (index++ < len)
		if (ft_strchr("NSEW0", map->map_matrix[size_map - 1][index]))
			return (1);
	return (0);
}

static int	check_line(char *line)
{
	int	index;
	int	result;

	index = -1;
	result = 0;
	while (line[++index] != '\0')
		if (line[index] == 'N' || line[index] == 'S'
			|| line[index] == 'E' || line[index] == 'W')
			result++;
	return (result);
}

int	check_player(char **map)
{
	int	index;
	int	qt_persons;

	index = -1;
	qt_persons = 0;
	while (map[++index])
		qt_persons += check_line(map[index]);
	if (qt_persons != 1)
		return (1);
	return (0);
}
