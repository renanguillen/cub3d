/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:13:37 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/23 01:37:42 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_detail_contents(t_data *data)
{
	if (check_detail_texture(data))
		return (1);
	if (check_detail_color(data))
		return (1);
	if (check_detail_map(data))
		return (1);
	return (0);
}

static void	extract_contents(t_data *data, char **file)
{
	data->map->no_path = extract_content(file, "NO ", 1);
	data->map->so_path = extract_content(file, "SO ", 1);
	data->map->we_path = extract_content(file, "WE ", 1);
	data->map->ea_path = extract_content(file, "EA ", 1);
	data->map->str_sky = extract_content(file, "C ", 1);
	data->map->str_floor = extract_content(file, "F ", 1);
	extract_map(data, file);
}

static void	configure_aux(t_data *data)
{
	data->map->color_floor = convert_hex(data->map->str_floor);
	data->map->color_sky = convert_hex(data->map->str_sky);
}

int	build_data(t_data *data)
{
	char	**file;

	file = read_file(data);
	if (file == NULL)
		return (1);
	if (check_contents_file(file))
	{
		ft_matrix_strdel(file);
		return (1);
	}
	extract_contents(data, file);
	if (check_detail_contents(data))
	{
		ft_matrix_strdel(file);
		return (1);
	}
	configure_aux(data);
	ft_matrix_strdel(file);
	return (0);
}
