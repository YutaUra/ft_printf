/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:40:38 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 21:52:52 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int			left_align;
	int			zero_padding;
	int			min_width;
	int			precision;
	char		conversion;
}				t_flag;

int				ft_printf(const char *src, ...);

/*
**  flag_helper.c
*/
void			initialize_flag(t_flag *flag);
void			show_flag(t_flag *flag);

/*
**  parse_helper.c
*/
void			parse_format(const char **src, va_list *args, t_flag *flag);
void			parse_precision(const char **src, va_list *args, t_flag *flag);
void			parse_min_width(const char **src, va_list *args, t_flag *flag);

/*
**  print_helper.c
*/
int				print_number(char *str, t_flag *flag, int minus);

/*
**  print1.c
*/
int				print_c(va_list *args, t_flag *flag);
int				print_s(va_list *args, t_flag *flag);
int				print_di(va_list *args, t_flag *flag);
int				print_u(va_list *args, t_flag *flag);
int				print_x(va_list *args, t_flag *flag);

/*
**  print2.c
*/
int				print_value(va_list *args, t_flag *flag);
int				print_modulo(t_flag *flag);
int				print_p(va_list *args, t_flag *flag);
int				print_string(char *str, t_flag *flag);

/*
**  utils.c
*/
unsigned int	count_digits(long long nb, unsigned int base);
void			put_str_repeat(char c, int cnt);
char			*char_repeat_join(char c, int repeat, char *str);
char			*ft_uitoa(unsigned int n);
char			*ft_utohex(size_t nb, int upper);

#endif
