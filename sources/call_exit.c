/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:40:11 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/15 20:40:25 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	call_exit(t_game *game, int exit_code, char *exit_message)
{
	game->exit_code = exit_code;
	if (game->exit_message)
		free(game->exit_message);
	game->exit_message = ft_strdup(exit_message);
	game->state = CLEAN_STATE;
	return (game->exit_code);
}
