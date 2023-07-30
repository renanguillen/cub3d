

#include "libft.h"

void	ft_strdel(char **pont)
{
	if (pont != NULL)
	{
		free(*pont);
		*pont = NULL;
	}
}
