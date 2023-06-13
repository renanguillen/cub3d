/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:09:35 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/13 09:27:07 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
* Frees the memory allocated for the game struct and exits the program with
* the proper exit code and message stored in the game struct.

* Returns nothing.
*/
void	cub3d_clean(t_game *game)
{
	int	exit_code;

	exit_code = game->exit_code;
	if (game->exit_message)
	{
		write(1, game->exit_message, ft_strlen(game->exit_message));
		free(game->exit_message);
	}
	free(game);
	exit(exit_code);
}