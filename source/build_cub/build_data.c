
#include "cub3d.h"

int	build_cub(t_data *data)
{
	char	**file;

	file = read_file(data);
	if (file == NULL)
		return (1);
	if (check_contents_file(file))
	{
		ft_matrix_strdel(file);
		return (1);
	}


}