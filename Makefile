# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/23 20:15:13 by yura              #+#    #+#              #
#    Updated: 2020/09/30 21:20:22 by yura             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
# CFLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a
SRCS := ft_printf.c flag_helper.c parse_helper.c print_helper.c print1.c print2.c utils.c 
OBJS := ${SRCS:%.c=%.o}
LIBFT_DIR := ./libft
LIBFT := ${LIBFT_DIR}/libft.a


all: ${NAME}

${LIBFT}:
	${MAKE}  -C ${LIBFT_DIR}
	cp ${LIBFT} ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	${MAKE} clean -C ${LIBFT_DIR}

fclean:
	${RM} ${NAME} ${OBJS}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

test: ${NAME}
	gcc ${NAME} main.c
	./a.out


bonus:

.PHONY : all, clean, fclean, re, bonus