/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:12:36 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/28 23:17:52 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"
# include "defines.h"
# include "exceptions.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

t_data	*init_all(char *patch);
t_data	*init(char *patch);
t_inter	*init_inter(void);
int		destroy(t_data *data);
int		build_data(t_data *data);
int		is_line_map(char *element);
int		convert_hex(char *color);
int		check_contents_file(char **file);
int		check_detail_texture(t_data *data);
int		check_detail_color(t_data *data);
int		check_detail_map(t_data *data);
int		check_walls(t_map *map);
int		check_player(char **map);
int		load_textures(t_data *data);
int		calculate_off_y(int y, double wall_height);
int		calculate_off_x(t_ray *ray);
int		render_loop(t_data **data);
int		check_player_position(t_data *data, double x, double y);
int		key_hook(int key, t_data *data);
int		copycolor(t_image *img, int x, int y);
int		wall_collision(double x, double y, t_data *data);
void	init_rays(t_data *data);
void	destroy_rays(t_data *data);
void	destroy_texture(t_data *data);
void	extract_map(t_data *data, char **file);
void	draw_wall(t_data *data, t_ray *ray, int x);
void	moviments_up_down(t_data *data, int key);
void	moviments_left_right(t_data *data, int key);
void	rotate(t_data *data, int key);
void	draw_pixel_color(t_image *img, int x, int y, int color);
void	render(t_data *data);
void	get_player(t_data *data);
void	vertical_intersection(t_data *data, t_ray *ray);
void	horizontal_intersection(t_data *data, t_ray *ray);
void	raycasting(t_data *data);
void	project_rays(t_data *data, t_ray *ray);
void	render_3d_projected_walls(t_data *data);
void	destroy_image(t_data *data);
void	destroy_player(t_player *player);
void	destroy_map(t_map *map);
char	*extract_content(char **file, char *key, int i);
char	**read_file(t_data *data);
double	normalize_angle(double angle);

#endif
