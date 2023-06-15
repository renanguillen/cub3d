/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:44:49 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/15 20:53:27 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef struct s_game	t_game;

typedef struct s_map
{
	int		floor_color;
	int		ceiling_color;
	t_game	*game;
}	t_map;

typedef struct s_game
{
	int		starting_orientation;
	int		exit_code;
	int		state;
	char	*exit_message;
	t_map	*map;
}	t_game;

#endif