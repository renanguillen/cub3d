#include "cub3d.h"

void	clear_ray(t_ray *ray)
{
	clear_inter(ray->hrz);
	clear_inter(ray->vert);
	ray->render->proj_wall_height = 0;
	ray->render->wall_bottom_pixel = 0;
	ray->render->wall_top_pixel = 0;
	ray->render->wall_strip_height = 0;
	ray->ray_angle = 0;
	ray->distance = 0;
	ray->vertical_wall = 0;
	ray->is_facing_down = 0;
	ray->is_facing_up = 0;
	ray->is_facing_right = 0;
	ray->is_facing_left = 0;
}

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