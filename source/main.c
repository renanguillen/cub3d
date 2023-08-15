
#include "cub3d.h"

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

static int verify_args(int argc, char **argv)
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

int main(int argc, char **argv)
{
    t_data  *data;

    if (verify_args(argc, argv))
        return (0);
    data = init_all(argv[1]);
	if (build_data(data))
	{
		destroy(data);
		return (0);
	}
	get_player(data);
	if (start_mlx(data))
		return (0);
	return (0);
}
