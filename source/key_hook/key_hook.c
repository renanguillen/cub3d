/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:14:24 by aminoru-          #+#    #+#             */
/*   Updated: 2023/08/19 03:14:25 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int key, t_data *data)
{
	if (key == KEY_W)
		moviments_up_down(data, UP);
	if (key == KEY_S)
		moviments_up_down(data, DOWN);
	if (key == KEY_A)
		moviments_left_right(data, LEFT);
	if (key == KEY_D)
		moviments_left_right(data, RIGHT);
	if (key == KEY_LEFT)
		rotate(data, KEY_LEFT);
	if (key == KEY_RIGHT)
		rotate(data, KEY_RIGHT);
	if (key == KEY_ESC || key == KEY_Q)
		destroy(data);
	return (0);
}
