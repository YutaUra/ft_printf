/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:40:38 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 08:03:40 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# define DEBUG 0

typedef struct	s_flag
{
	int			left_align;
	int			zero_padding;
	int			min_width;
	int			precision;
	char		conversion;
}				t_flag;

int ft_printf(const char *src, ...);

void	min_width(const char **str, va_list *args, t_flag *flag);
void	precision(const char **str, va_list *args, t_flag *flag);

unsigned int	count_digits(long long nb, unsigned int base);
void put_str_repeat(char *str, int cnt);
char *char_repeat(char c, int repeat);
char *char_repeat_join(char c, int repeat, char *str);
char *ft_uitoa(unsigned int n);
char			*ft_utohex(size_t nb, int upper);

#endif
