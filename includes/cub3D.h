/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:41:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/15 20:41:13 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//REMOVER BIBLIOTECAS QUE NÃO SÃO USADAS PELO PROGRAMA PARA ENTREGA
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./cub3D_structs.h"
# include "./cub3D_defines.h"

//MAIN

int		call_exit(t_game *game, int exit_code, char *exit_message);

//STATES

void	cub3d_clean(t_game *game);
int		cub3d_init(t_game *game, int argc, char **argv);

//FT_TOOLS

void	*ft_calloc(size_t num_elements, size_t element_size);
char	*ft_strdup(char *tobecopied);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif