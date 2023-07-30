

#include "libft.h"

int	ft_matrix_strlen(char **matrix)
{
	int	len;

	len = 0;
	if (matrix == NULL)
		return (-1);
	while (matrix[len] != 0)
		len++;
	return (len);
}
