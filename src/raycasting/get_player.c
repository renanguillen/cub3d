/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:14:47 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/28 14:16:22 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_angle(t_data *data, int y, int x)
{
	if (data->map->map_matrix[y][x] == 'N')
		data->player->angle = PI / 2;
	if (data->map->map_matrix[y][x] == 'S')
		data->player->angle = (PI * 3) / 2;
	if (data->map->map_matrix[y][x] == 'E')
		data->player->angle = 0;
	if (data->map->map_matrix[y][x] == 'W')
		data->player->angle = PI;
}

void	get_player(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map->map_matrix[++y])
	{
		x = -1;
		while (data->map->map_matrix[y][++x])
		{
			if (ft_strchr("NSWE", data->map->map_matrix[y][x]))
			{
				data->player->pos_x = ((x + 0.5) * TILE_SIZE);
				data->player->pos_y = ((y + 0.5) * TILE_SIZE);
				set_angle(data, y, x);
				data->map->map_matrix[y][x] = '0';
			}
		}	
	}
}
