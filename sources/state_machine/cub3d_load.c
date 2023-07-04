/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:45:12 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/07/04 11:26:52 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	no_button_pressed(void *game)
{
	(void)game;
	return (CONTROL_OK);
}

static int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(game->mlx->ptr, game->mlx->win);
	printf("Keypress: %d\n", keysym);
	return (CONTROL_OK);
}

static int	handle_keyrelease(int keysym, void *game)
{
	(void)game;
	printf("Keyrelease: %d\n", keysym);
	return (CONTROL_OK);
}

static int	init_controls(t_game *game)
{
	mlx_loop_hook(game->mlx->ptr, &no_button_pressed, game->mlx);
	mlx_hook(game->mlx->ptr, KeyPress, KeyPressMask, &handle_keypress, game->mlx);
	mlx_hook(game->mlx->ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, game->mlx);
	return (CONTROL_OK);
}

static int	init_mlx(t_game *game)
{
	game->mlx->ptr = mlx_init();
	if (game->mlx->ptr == NULL)
		return (call_exit(game, ERR_MEMORY, MSG_MEMORY));
	game->mlx->win = mlx_new_window(game->mlx->ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (game->mlx->win == NULL)
		return (call_exit(game, ERR_MEMORY, MSG_MEMORY));
	return (CONTROL_OK);
}

int	cub3d_load(t_game *game)
{
	init_mlx(game);
	init_controls(game);
	mlx_loop(game->mlx->ptr);
	return (CONTROL_OK);
}
