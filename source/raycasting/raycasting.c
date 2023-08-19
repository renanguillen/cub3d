#include "cub3d.h"

void	raycasting(t_data *data)
{
	double	ray_angle;
	int		column_id;

	ray_angle = normalize_angle(data->player->angle + (FOV_ANGLE / 2));
	column_id = 0;
	while (column_id < NUM_RAYS)
	{
		clear_ray(&data->rays[column_id]);
		data->rays[column_id].ray_angle = ray_angle;
		project_rays(data, &data->rays[column_id]);
		calc_dist(data, &data->rays[column_id]);
		ray_angle = normalize_angle(ray_angle - FOV_ANGLE / NUM_RAYS);
		column_id++;
	}
	render_3d_projected_walls(data);
}