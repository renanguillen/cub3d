/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:50:14 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/13 08:39:01 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

// General

# define YES 1
# define NO 0

// States

//EXIT: The program is about to exit.
# define EXIT_STATE -1
//INIT: The program is initializing, memory is being allocated and parameters
//are being set.
# define INIT_STATE 0
//LOAD: Loading textures, sprites, map, etc.
# define LOAD_STATE 1
//MENU: Displaying the menu, controls are set to menu controls.
# define MENU_STATE 2
//PLAY: The game is running, controls are set to game controls.
# define PLAY_STATE 3

// Exit codes

# define CONTROL_OK 0
# define ERR_ARGS 1
# define ERR_MAP 2
# define ERR_MEMORY 3

// Exit messages

# define MSG_ARGS "Error(1): Invalid number of arguments.\n"
# define MSG_MAP "Error(2): Invalid map path or configuration.\n"
# define MSG_MEMORY "Error(3): Memory allocation failed.\n"

#endif