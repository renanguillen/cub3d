
#include "cub3d.h"


static void extract_contents(t_data *data, char **file)
{
	data->map->no_path = extract_content(file, "NO ",1);
	data->map->so_path = extract_content(file, "SO ",1);
	data->map->we_path = extract_content(file, "WE ",1);
	data->map->ea_path = extract_content(file, "EA ",1);
	data->map->str_sky = extract_content(file, "C ",1);
	data->map->str_floor = extract_content(file, "F ",1);
	extract_map(data, file);
}

int	build_cub(t_data *data)
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

}