/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:41:54 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/07/04 11:17:28 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//NEEDS TO BE IMPLEMENTED
static int	validate_map(t_game *game, int fd)
{
	(void)fd;
	(void)game;
	return (CONTROL_OK);
}

/*
* Checks if the map file exists and can be opened. If it can, calls
* validate_map to check the map validation.

* Returns CONTROL_OK if everything is ok.
*/
static int	check_map(t_game *game, char *map_path)
{
	int		fd;
	size_t	nlen;

	nlen = ft_strlen(map_path);
	if (ft_strncmp(&map_path[nlen - 4], ".cub", 4))
		return (call_exit(game, ERR_MAP, MSG_EXTENSION));
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (call_exit(game, ERR_MAP, MSG_UNABLE_OPEN));
	else
		validate_map(game, fd);
	close (fd);
	game->state = LOAD_STATE;
	return (CONTROL_OK);
}

/*
* Checks if the number of arguments is correct, and calls check_map to check
* the map validation.

* Returns CONTROL_OK if everything is ok.
*/
int	cub3d_init(t_game *game, int argc, char **argv)
{
	if (argc == 2)
		return (check_map(game, argv[1]));
	else
		return (call_exit(game, ERR_ARGS, MSG_ARGS));
}
