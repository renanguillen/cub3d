#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"
# include "defines.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

/* build_data.c */
int		build_cub(t_data *data);
/* build_data.c */
t_data  *init_all(char *patch);

#endif