
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrix_strdup(char **matrix)
{
	char	**result;
	int		size;
	int		index;

	index = 0;
	if (matrix == NULL)
		return (NULL);
	size = ft_matrix_strlen(matrix);
	result = ft_calloc(sizeof(char *), size);
	while (index < size)
	{
		result[index] = ft_strdup(matrix[index]);
		index++;
	}
	return (result);
}
