/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:40:41 by yura              #+#    #+#             */
/*   Updated: 2020/10/02 22:34:35 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  ft_printf
**
**    format configuration
**      %[flag][minimum field width]
**        [.precision][length modifier][conversions]
**
**      flag
**        - A minus sign `-' which specifies left adjustment
**          of the output in the indicated field;
**        0 A zero `0' character indicating that zero-padding
**          should be used rather than blank-padding.
**          A `-' overrides a `0' if both are used;
**
**      length modifier (only bonus)
**        hh
**        h
**        l
**        ll
**        L
**        j
**        z
**        t
**
**      conversions
**        c int to unsigned char
**        s string
**        p pointer
**        d int with base 10
**        i int with base 10
**        u unsigned int with base 10
**        x unsigned int with base 16 (using "abcdef")
**        X unsigned int with base 16 (using "ABCDEF")
**        % just "%"
**
**      example
**        - %d -> "15"
**          - flag:                NULL
**          - minimum field width: NULL
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
**        - %zd -> "15"
**          - flag:                NULL
**          - minimum field width: NULL
**          - precision:           NULL
**          - length modifier:     z
**          - conversions:         d
**        - %4d -> "  15"
**          - flag:                NULL
**          - minimum field width: 4
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
**        - %.3d -> "015"
**          - flag:                NULL
**          - minimum field width: NULL
**          - precision:           3
**          - length modifier:     NULL
**          - conversions:         d
**        - %4.3d -> "0015"
**          - flag:                NULL
**          - minimum field width: 4
**          - precision:           3
**          - length modifier:     NULL
**          - conversions:         d
**        - %*d
**          - flag:                NULL
**          - minimum field width: *
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
**        - %.*d
**          - flag:                NULL
**          - minimum field width: NULL
**          - precision:           *
**          - length modifier:     NULL
**          - conversions:         d
**        - %*.*d
**          - flag:                NULL
**          - minimum field width: *
**          - precision:           *
**          - length modifier:     NULL
**          - conversions:         d
**        - %05d -> "00015"
**          - flag:                0
**          - minimum field width: 5
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
**        - %- d -> "15   "
**          - flag:                -
**          - minimum field width: 5
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
*/

static int	ft_printf_main(const char *src, t_flag *flag, va_list *args)
{
	int	cnt;

	cnt = 0;
	while (*src)
	{
		if (*src == '%')
		{
			initialize_flag(flag);
			src++;
			parse_format(&src, args, flag);
			if (flag->conversion == '\0')
				return (cnt);
			cnt += print_value(args, flag);
		}
		else
		{
			ft_putchar_fd(*src++, 1);
			cnt++;
		}
	}
	return (cnt);
}

int			ft_printf(const char *src, ...)
{
	va_list	args;
	t_flag	*flag;
	int		cnt;

	if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
		return (-1);
	va_start(args, src);
	cnt = ft_printf_main(src, flag, &args);
	free(flag);
	va_end(args);
	return (cnt);
}
