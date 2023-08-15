
#include "cub3d.h"

static int verify_args(int argc, char **argv)
{
	int		len;
	char	*str;

	if (argc < 2)
	{
		printf("Error\nWrong numbers of arguments\n");
		return (1);
	}
	else
	{
		len = 0;
		str = ft_strrchr(argv[1], '.');
		if (str)
		{
			len = ft_strlen(str);
			if (!ft_memcmp(str, ".cub", len))
				return (0);
		}
		printf("Error\nInvalid map extension. Use .cub\n");
		return (1);
	}
	return (0);   
}

int main(int argc, char **argv)
{
    t_data  *data;

    if (verify_args(argc, argv))
        return (0);
    data = init_all(argv[1]);
	if (build_data(data))
	{
		destroy(data);
		return (0);
	}
	get_player(data);
	return (0);
}
