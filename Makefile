
NAME = cub3d

LIBFTPATH = ./lib/libft/
LIBFT = ./lib/libft/libft.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
INCS = -I ./include/
SRCS = 	./src/main.c \


OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
			make -C $(LIBFTPATH)
			${CC} -o ${NAME} ${CFLAG} ${OBJS} ${LIBFT} ${READFLAGS}

.c.o:
			${CC} ${CFLAG} ${INCS} -c $< -o ${<:.c=.o}

clean:
			make clean -C ./lib/libft
			rm -f ${OBJS}

fclean: clean
			make fclean -C ./lib/libft
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re