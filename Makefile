NAME = cub3D

PATH_INCS = ./includes/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/
PATH_STTS = $(PATH_SRCS)state_machine/
PATH_TOOL = $(PATH_SRCS)tools/

SRCS = $(addprefix $(PATH_TOOL),\
		ft_calloc.c\
		ft_strdup.c\
		ft_strlen.c)\
		$(addprefix $(PATH_STTS),\
		cub3d_clean.c)\
		$(addprefix $(PATH_SRCS),\
		check_args.c\
		main.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(PATH_INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)state_machine/
	@mkdir -p $(PATH_OBJS)tools/
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(PATH_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

r: all
	@clear
	@./cub3D ./maps/run.cub

n:
	@clear
	@norminette ./sources ./includes

PHONY: all clean fclean re r n