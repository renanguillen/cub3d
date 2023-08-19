/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:14:29 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/19 03:14:31 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	face_down(t_data *data, t_ray *ray, int x, int y)
{
	int	off_x;
	int	off_y;

	off_x = calculate_off_x(ray);
	off_y = calculate_off_y(y, ray->render->proj_wall_height);
	if (ray->vertical_wall == 0)
		draw_pixel_color(data->image, x, y,
			copycolor(data->s_texture, off_x, off_y));
	else
	{
		if (ray->is_facing_right == 0)
			draw_pixel_color(data->image, x, y,
				copycolor(data->w_texture, off_x, off_y));
		else
			draw_pixel_color(data->image, x, y,
				copycolor(data->e_texture, off_x, off_y));
	}
}

static void	face_up(t_data *data, t_ray *ray, int x, int y)
{
	int	off_x;
	int	off_y;

	off_x = calculate_off_x(ray);
	off_y = calculate_off_y(y, ray->render->proj_wall_height);
	if (ray->vertical_wall == 0)
		draw_pixel_color(data->image, x, y,
			copycolor(data->n_texture, off_x, off_y));
	else
	{
		if (ray->is_facing_right == 1)
			draw_pixel_color(data->image, x, y,
				copycolor(data->e_texture, off_x, off_y));
		else
			draw_pixel_color(data->image, x, y,
				copycolor(data->w_texture, off_x, off_y));
	}
}

void	draw_wall(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = ray->render->wall_top_pixel;
	while (y < ray->render->wall_bottom_pixel)
	{
		if (ray->is_facing_up == 1)
			face_up(data, ray, x, y);
		else
			face_down(data, ray, x, y);
		y++;
	}
}
