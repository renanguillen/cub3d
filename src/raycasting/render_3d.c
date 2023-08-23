/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:15:19 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/23 14:28:23 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_sky(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = -1;
	while (++y < ray->render->wall_top_pixel)
		draw_pixel_color(data->image, x, y, data->map->color_sky);
}

static void	draw_bottom(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = ray->render->wall_bottom_pixel;
	while (y < WIN_HEIGHT)
	{
		draw_pixel_color(data->image, x, y, data->map->color_floor);
		y++;
	}
}

static void	calculate_columns(t_ray *ray)
{
	ray->render->wall_top_pixel = (WIN_HEIGHT / 2)
		- (ray->render->proj_wall_height / 2);
	if (ray->render->wall_top_pixel < 0)
		ray->render->wall_top_pixel = 0;
	ray->render->wall_bottom_pixel = (WIN_HEIGHT / 2)
		+ (ray->render->proj_wall_height / 2);
	if (ray->render->wall_bottom_pixel > WIN_HEIGHT)
		ray->render->wall_bottom_pixel = WIN_HEIGHT;
}

void	render_3d_projected_walls(t_data *data)
{
	int		x;
	t_ray	*ray;

	x = -1;
	while (++x < NUM_RAYS)
	{
		ray = &data->rays[x];
		ray->render->proj_wall_height = (TILE_SIZE / ray->distance)
			* data->dist_proj_plane;
		ray->render->wall_strip_height = ceil(ray->render->proj_wall_height);
		calculate_columns(ray);
		draw_sky(data, ray, x);
		draw_wall(data, ray, x);
		draw_bottom(data, ray, x);
	}
}
