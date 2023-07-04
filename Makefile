# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 01:31:01 by aminoru-          #+#    #+#              #
#    Updated: 2023/07/04 11:42:24 by ridalgo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

PATH_INCS = ./includes/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/
PATH_STTS = $(PATH_SRCS)state_machine/
PATH_TOOL = $(PATH_SRCS)tools/

SRCS = $(addprefix $(PATH_TOOL),\
		ft_calloc.c\
		ft_strdup.c\
		ft_strlen.c\
		ft_strncmp.c)\
		$(addprefix $(PATH_STTS),\
		cub3d_clean.c\
		cub3d_init.c\
		cub3d_load.c)\
		$(addprefix $(PATH_SRCS),\
		call_exit.c\
		main.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -L /opt/X11/lib -L /usr/local/lib -lX11 -lXext -lmlx -lm
IFLAGS = -I $(PATH_INCS) -I /opt/X11/include -I /usr/local/include

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)


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