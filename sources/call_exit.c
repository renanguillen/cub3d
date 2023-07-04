/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:40:11 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/07/04 11:18:20 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	call_exit(t_game *game, int exit_code, char *exit_message)
{
	game->exit_code = exit_code;
	if (game->exit_message)
		free(game->exit_message);
	game->exit_message = ft_strdup(exit_message);
	if (game->mlx->win)
		free(game->mlx->win);
	if (game->mlx->ptr)
	{
		mlx_destroy_display(game->mlx->ptr);
		free(game->mlx->ptr);
	}
	game->state = CLEAN_STATE;
	return (game->exit_code);
}
