/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:41:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/06/13 08:45:07 by ridalgo-         ###   ########.fr       */
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

int		check_args(int argc, char **argv);

//FT_TOOLS

void	*ft_calloc(size_t num_elements, size_t element_size);
int		ft_strlen(char *str);


#endif