/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:15:54 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/22 03:10:04 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_image	*init_image(void)
{
	t_image	*image;

	image = NULL;
	image = ft_calloc(sizeof(t_image), 1);
	if (image == NULL)
		return (NULL);
	image->pont = NULL;
	image->patch = NULL;
	return (image);
}

static t_map	*init_map(char *patch)
{
	t_map	*map;

	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	map->patch = NULL;
	if (patch != NULL)
		map->patch = ft_strdup(patch);
	map->map_matrix = NULL;
	map->nb_lines = 0;
	map->nb_columns = 0;
	map->height_px = 0;
	map->width_px = 0;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->str_floor = NULL;
	map->str_sky = NULL;
	return (map);
}

static t_player	*init_player(void)
{
	t_player	*player;

	player = NULL;
	player = ft_calloc(sizeof(t_player), 1);
	if (player == NULL)
		return (NULL);
	player->pos_x = 0;
	player->pos_y = 0;
	player->angle = 0;
	player->turn_speed = (PI / 180);
	return (player);
}

t_data	*init(char *patch)
{
	t_data	*data;

	data = NULL;
	data = ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (NULL);
	data->map = init_map(patch);
	data->image = init_image();
	data->n_texture = NULL;
	data->s_texture = NULL;
	data->w_texture = NULL;
	data->e_texture = NULL;
	data->player = init_player();
	data->dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	init_rays(data);
	data->mlx = NULL;
	data->win = NULL;
	data->close_game = 0;
	return (data);
}


static t_render	*init_render(void)
{
	t_render	*render;

	render = NULL;
	render = ft_calloc(sizeof(t_render), 1);
	if (render == NULL)
		return (NULL);
	render->proj_wall_height = 0;
	render->wall_bottom_pixel = 0;
	render->wall_top_pixel = 0;
	render->wall_strip_height = 0;
	return (render);
}

t_inter	*init_inter(void)
{
	t_inter	*result;

	result = NULL;
	result = ft_calloc(sizeof(t_inter), 1);
	result->found_wall = 0;
	result->wall_x = 0;
	result->wall_y = 0;
	result->step_x = 0;
	result->step_y = 0;
	result->distance = 0;
	return (result);
}

void	init_rays(t_data *data)
{
	int	index;

	index = 0;
	while (index < NUM_RAYS)
	{
		data->rays[index].hrz = init_inter();
		data->rays[index].vert = init_inter();
		data->rays[index].render = init_render();
		data->rays[index].ray_angle = 0;
		data->rays[index].distance = 0;
		data->rays[index].vertical_wall = 0;
		data->rays[index].is_facing_down = 0;
		data->rays[index].is_facing_up = 0;
		data->rays[index].is_facing_right = 0;
		data->rays[index].is_facing_left = 0;
		index++;
	}
}

int	render_loop(t_data **data)
{
	render(*data);
	return (0);
}

static int	start_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Error\nNo graphical interface.\n");
		destroy(data);
		exit(1);
	}
	if (load_textures(data))
	{
		destroy(data);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!data->win)
	{
		printf("Error\nNo graphical interface.\n");
		destroy(data);
		exit(1);
	}
	data->image->pont = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image->patch = mlx_get_data_addr(data->image->pont, &data->image->bpp,
			&data->image->size_line, &data->image->endian);
	return (0);
}

static int	check_args(int argc, char **argv)
{
	int		len;
	char	*str;

	if (argc < 2)
	{
		printf("Error\nWrong numbers of arguments\n");
		return (1);
	}
	else
	{
		len = 0;
		str = ft_strrchr(argv[1], '.');
		if (str)
		{
			len = ft_strlen(str);
			if (!ft_memcmp(str, ".cub", len))
				return (0);
		}
		printf("Error\nInvalid map extension. Use .cub\n");
		return (1);
	}
	return (0);
}

static int	close_game(t_data *data)
{
	mlx_loop_end(data->mlx);
	destroy(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (0);
	data = init(argv[1]);
	if (build_data(data))
	{
		destroy(data);
		return (0);
	}
	get_player(data);
	if (start_mlx(data))
		return (0);
	mlx_hook(data->win, KEY_PRESS, 1L << 0, key_hook, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, close_game, data);
	mlx_loop_hook(data->mlx, &render_loop, &data);
	mlx_loop(data->mlx);
	destroy(data);
	return (0);
}
