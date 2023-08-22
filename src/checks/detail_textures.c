/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:13:33 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/23 00:20:28 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_path(char *path)
{
	if (!(ft_strncmp(path, "./textures/", 11) == 0))
	{
		printf(ERROR_TEXTURE_DIR);
		return (1);
	}
	if (!(ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4) == 0))
	{
		printf(ERROR_TEXTURE_EXTENSION);
		return (1);
	}
	return (0);
}

int	check_detail_texture(t_data *data)
{
	int	status;

	status = 0;
	status += check_path(data->map->no_path);
	status += check_path(data->map->so_path);
	status += check_path(data->map->we_path);
	status += check_path(data->map->ea_path);
	if (status != 0)
		return (1);
	return (0);
}
