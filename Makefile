# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 03:16:04 by aminoru-          #+#    #+#              #
#    Updated: 2023/08/23 01:24:21 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFTPATH = ./libft/
LIBFT = ./libft/libft.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
MLX_LIB = -lbsd -lmlx -lXext -lX11 -lm -lz

INCS = -I ./include/
SRCS = 	./src/main.c \
		./src/init.c \
		./src/load.c \
		./src/key_hook.c \
		./src/checks/contents_file.c \
		./src/checks/refined_color.c \
		./src/checks/refined_map_aux.c \
		./src/checks/refined_map.c \
		./src/checks/refined_textures.c \
		./src/extract/extract_maps.c \
		./src/extract/extract_contens.c \
		./src/build/build_data.c \
		./src/build/build_tools.c \
		./src/destroy/destroy.c \
		./src/destroy/destroy_tools.c \
		./src/raycasting/draw_all.c \
		./src/raycasting/intersection.c \
		./src/raycasting/offset.c \
		./src/raycasting/raycasting.c \
		./src/raycasting/render_3d.c \
		./src/raycasting/get_player.c \
		./src/raycasting/moviments.c \
		./src/raycasting/project_rays.c \
		./src/raycasting/ray_tools.c \
		./src/raycasting/render.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
			make -C $(LIBFTPATH)
			${CC} ${CFLAG} ${INCS} -no-pie -o ${NAME} ${OBJS} ${LIBFT} $(MLX_LIB)

.c.o:
			${CC} ${CFLAG} ${INCS} -c $< -o ${<:.c=.o}

clean:
			make clean -C ./libft
			rm -f ${OBJS}

fclean: clean
			make fclean -C ./libft
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re