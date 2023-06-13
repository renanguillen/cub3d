/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:41:54 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/13 08:47:58 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//NEEDS TO BE IMPLEMENTED
static int	validate_map(int fd)
{
	(void)fd;
	return (CONTROL_OK);
}

/*
* Checks if the map file exists and can be opened. If it can, calls
* validate_map to check the map validation.

* Returns CONTROL_OK if everything is ok.
*/
static int	check_map(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		write(2, MSG_MAP, ft_strlen(MSG_MAP));
		exit(ERR_MAP);
	}
	else
		validate_map(fd);
	close (fd);
	return (CONTROL_OK);
}

/*
* Checks if the number of arguments is correct, and calls check_map to check
* the map validation.

* Returns CONTROL_OK if everything is ok.
*/
int	check_args(int argc, char **argv)
{
	if (argc == 2)
		check_map(argv[1]);
	else
	{
		write(2, MSG_ARGS, ft_strlen(MSG_ARGS));
		exit(ERR_ARGS);
	}
	return (CONTROL_OK);
}
