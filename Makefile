# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 03:16:04 by aminoru-          #+#    #+#              #
#    Updated: 2023/08/19 03:47:37 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFTPATH = ./libft/
LIBFT = ./libft/libft.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
INCS = -I ./include/
SRCS = 	./src/main.c \
		./src/init/init_1 ./src/init/init_2 \
		./src/build_cub/checks/contents_file.c \
		./src/build_cub/checks/refined_color.c \
		./src/build_cub/checks/refined_map_aux.c \
		./src/build_cub/checks/refined_map.c \
		./src/build_cub/checks/refined_textures.c \
		./src/build_cub/build_data.c \
		./src/build_cub/extract_maps.c \
		./src/build_cub/read_file.c \
		./src/build_cub/build_tools.c \
		./src/build_cub/extract_contens.c \
		./src/build_cub/load_texture.c \
		./src/destroy/destroy.c ./src/destroy/destroy_tools.c \
		./src/key_hook/key_hook.c \
		./src/raycasting/draw_all.c ./src/raycasting/intersection.c \
		./src/raycasting/offset.c ./src/raycasting/raycasting.c \
		./src/raycasting/render_3d.c ./src/raycasting/get_player.c \
		./src/raycasting/moviments.c ./src/raycasting/project_rays.c \
		./src/raycasting/ray_tools.c ./src/raycasting/render.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
			make -C $(LIBFTPATH)
			${CC} -o ${NAME} ${CFLAG} ${OBJS} ${LIBFT} 

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