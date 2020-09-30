# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/23 20:15:13 by yura              #+#    #+#              #
#    Updated: 2020/09/30 03:49:03 by yura             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
# CFLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a
SRCS := ft_printf.c utils.c
OBJS := ${SRCS:%.c=%.o}
LIBFT := ./libft


all: ${LIBFT} ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFT}
	cp ${LIBFT}/libft.a ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	${MAKE} clean -C ${LIBFT}

fclean:
	${RM} ${NAME} ${OBJS}
	${MAKE} fclean -C ${LIBFT}

re: fclean all

test: ${NAME}
	gcc ${NAME} main.c
	./a.out


bonus:

.PHONY : all, clean, fclean, re, bonus