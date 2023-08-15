#include "cub3d.h"

int	destroy(t_data *data)
{
	data->close_game = 1;
	if (data == NULL)
		return (1);
	destroy_rays(data);
	destroy_player(data->player);
	destroy_image(data);
	destroy_texture(data);
	destroy_map(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free (data->mlx);
	}
	free(data);
	data = NULL;
	exit (0);
	return (0);
}
