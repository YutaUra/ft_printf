# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/23 20:15:13 by yura              #+#    #+#              #
#    Updated: 2020/10/10 11:06:54 by yura             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a
SRCS := ft_printf.c flag_helper.c parse_helper.c print_helper.c print1.c print2.c utils.c string_utils.c
OBJS := ${SRCS:%.c=%.o}
LIBFT_DIR := ./libft
LIBFT := ${LIBFT_DIR}/libft.a
ARGS := 


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
	gcc -Wformat=0 ${NAME} main.c
	./a.out ${ARGS}


bonus:

.PHONY : all, clean, fclean, re, bonus