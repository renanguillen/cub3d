/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:15:23 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/19 03:15:24 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pixel_color(t_image *img, int x, int y, int color)
{
	char	*tmp;

	tmp = img->patch + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *) tmp = color;
}

int	copycolor(t_image *img, int x, int y)
{
	char	*tmp;
	char	*color;

	tmp = img->data_img;
	color = &tmp[(y * img->size_line + x * (img->bpp / 8))];
	return (*(unsigned int *) color);
}

void	render(t_data *data)
{
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image->pont, 0, 0);
}
