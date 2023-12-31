/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:13:19 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/23 00:15:15 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_node(char *node)
{
	int	count;
	int	size;

	count = -1;
	size = ft_strlen(node);
	if (size < 0 || size > 3)
		return (1);
	while (++count < size)
		if (!ft_isdigit(node[count]))
			return (1);
	return (0);
}

static int	check_color(char *color)
{
	char	**rgb_color;
	int		index;
	int		nb;

	index = -1;
	rgb_color = ft_split(color, ',');
	if (ft_matrix_strlen(rgb_color) != 3)
	{
		ft_matrix_strdel(rgb_color);
		return (1);
	}
	while (++index < 3)
	{
		nb = ft_atoi(rgb_color[index]);
		if (!(nb > -1 && nb < 256) || check_node(rgb_color[index]))
		{
			ft_matrix_strdel(rgb_color);
			return (1);
		}
	}
	ft_matrix_strdel(rgb_color);
	return (0);
}

int	check_detail_color(t_data *data)
{
	if (check_color(data->map->str_sky))
	{
		printf(ERROR_SKY_COLOR);
		return (1);
	}
	if (check_color(data->map->str_floor))
	{
		printf(ERROR_FLOOR_COLOR);
		return (1);
	}
	return (0);
}
