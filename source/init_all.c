


#include "cub3d.h"

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

t_data  *init(char *patch)
{
    t_data  *data;

    data = NULL;
    data = ft_calloc(sizeof(t_data), 1);
    if (data == NULL)
        return (NULL);
    data->map = init_map(patch);

}