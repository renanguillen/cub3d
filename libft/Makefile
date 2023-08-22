# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 16:30:03 by aminoru-          #+#    #+#              #
#    Updated: 2023/08/22 02:54:57 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
LIBFT	= libft.h
GETNEXTLINE = get_next_line.h
SRCS	=	ft_atoi.c ft_memchr.c ft_strdel.c ft_strtrim.c \
			ft_bzero.c ft_memcmp.c ft_strdup.c ft_substr.c \
			ft_calloc.c ft_memcpy.c ft_striteri.c ft_tolower.c \
			ft_isalnum.c ft_memmove.c ft_strjoin.c ft_toupper.c \
			ft_isalpha.c ft_memset.c ft_strlcat.c \
			ft_isascii.c ft_putchar_fd.c ft_strlcpy.c  \
			ft_isdigit.c ft_putendl_fd.c ft_strlen.c  \
			ft_isprint.c ft_matrix_join.c ft_putnbr_fd.c ft_strmapi.c \
			ft_itoa.c ft_matrix_strdel.c ft_putstr_fd.c ft_strncmp.c \
			ft_matrix_strdup.c ft_split.c ft_strnstr.c \
			ft_matrix_strlen.c ft_strchr.c ft_strrchr.c \
			get_next_line.c get_next_line_1.c ft_linebreak.c \
			ft_strindexcpy.c ft_strjoin_free1.c

OBJS	=	${SRCS:.c=.o}

all: 		${NAME} 

${NAME}: 	${OBJS} $(LIBFT) $(GETNEXTLINE)
				ar -rcs ${NAME} ${OBJS}
				ranlib ${NAME}

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
				rm -f ${OBJS} ${OBJS_BONUS}

fclean: 	clean
				rm -f ${NAME}

re: 		fclean all

.PHONY: all clean fclean re 