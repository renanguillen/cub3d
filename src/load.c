/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:14:00 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/23 01:14:28 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_image	*load_xpm(t_data *data, char *path)
{
	t_image	*result;
	int		w;
	int		h;

	result = NULL;
	result = ft_calloc(sizeof(t_image), 1);
	result->pont = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (result->pont == NULL)
	{
		printf(ERROR_TEXTURE_FILE);
		free(result);
		return (NULL);
	}
	result->data_img = mlx_get_data_addr(result->pont,
			&result->bpp, &result->size_line, &result->endian);
	if (result->data_img == NULL)
	{
		printf(ERROR_MLX_DATA_IMAGE);
		mlx_destroy_image(data->mlx, result->pont);
		free(result);
		return (NULL);
	}
	return (result);
}

int	load_textures(t_data *data)
{
	data->n_texture = load_xpm(data, data->map->no_path);
	if (data->n_texture == NULL)
		return (1);
	data->s_texture = load_xpm(data, data->map->so_path);
	if (data->s_texture == NULL)
		return (1);
	data->e_texture = load_xpm(data, data->map->ea_path);
	if (data->e_texture == NULL)
		return (1);
	data->w_texture = load_xpm(data, data->map->we_path);
	if (data->w_texture == NULL)
		return (1);
	return (0);
}

static int	open_file(char *patch, int *fd)
{
	*fd = open(patch, O_RDONLY);
	if (*fd == -1)
		return (1);
	return (0);
}

static char	**load_file(int fd)
{
	int		count;
	char	*line;
	char	**file;

	line = NULL;
	file = NULL;
	count = get_next_line(fd, &line);
	file = ft_matrix_join(NULL, line);
	ft_strdel(&line);
	while (count)
	{
		line = NULL;
		count = get_next_line(fd, &line);
		file = ft_matrix_join(file, line);
		ft_strdel(&line);
	}
	return (file);
}

char	**read_file(t_data *data)
{
	int		fd;
	char	**file;

	file = NULL;
	if (open_file(data->map->patch, &fd))
	{
		printf(ERROR_OPEN_FILE, data->map->patch);
		return (NULL);
	}
	file = load_file(fd);
	close(fd);
	return (file);
}
