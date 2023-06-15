/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 03:50:38 by aminoru-          #+#    #+#             */
/*   Updated: 2023/06/15 04:00:15 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
* Load map in str

* Returns CONTROL_OK if everything is ok.
*/

char	*map_load(char *name_map)
{
	int		fd;

	fd = open_map(name_map);
	// need read map
	// need convert list map to str
	return (CONTROL_OK);
}

/*
* Checks if the map file exists, if is a correct extension and can be opened. If it can, calls
* validate_map to check the map validation.

* Returns File descriptor if everything is ok.
*/

int	open_map(char *name)
{
	size_t	nlen;
	int		fd;

	nlen = ft_strlen(name);
	if (ft_strncmp(&name[nlen - 4], ".cub", 4))
	{
		write(2, MSG_EXTENSION, ft_strlen(MSG_EXTENSION));
		exit(ERR_ARGS);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		write(2, MSG_UNABLE_OPEN, ft_strlen(MSG_UNABLE_OPEN));
		exit(ERR_ARGS);
	}
	return (fd);
}
