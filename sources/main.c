/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:40:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/15 20:47:24 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
* The main function is responsible for the game loop. Checks the arguments,
* allocates memory for the game struct, and calls the functions responsible for
* each state of the game.

* Returns CONTROL_OK if everything is ok.
*/
int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		write(2, MSG_MEMORY, ft_strlen(MSG_MEMORY));
		exit(ERR_MEMORY);
	}
	while (YES)
	{
		if (game->state == INIT_STATE)
			cub3d_init(game, argc, argv);
		else if (game->state == LOAD_STATE)
			game->state = MENU_STATE;
		else if (game->state == MENU_STATE)
			game->state = PLAY_STATE;
		else if (game->state == PLAY_STATE)
			game->state = CLEAN_STATE;
		else if (game->state == CLEAN_STATE)
			cub3d_clean(game);
	}
	return (CONTROL_OK);
}
