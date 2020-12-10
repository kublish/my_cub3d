/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 04:15:03 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 16:01:17 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "helper.h"
#include "printer.h"
#include "get_format.h"

int	ft_printf_x(char **input, va_list ap, int caps)
{
	t_format_data	fd;
	t_ull			val;

	fd.base = 16;
	get_format(input, &fd, ap);
	val = read_arg(ap, &fd);
	fd.len = numlen(val, fd.base, fd.prec);
	fd.caps = caps;
	if (val == 0)
		fd.pound = 0;
	fd.width -= fd.pound * 2;
	if (!((fd.zero && fd.prec == -1) || fd.minus))
		loop_char(' ', fd.width - fd.len);
	if (fd.pound)
		buffer(caps ? "0X" : "0x", 2);
	if (fd.zero && fd.prec == -1 && !(fd.minus))
		loop_char('0', fd.width - fd.len);
	my_putnbr_base(val, fd.prec, &fd);
	if (fd.minus)
		loop_char(' ', fd.width - fd.len);
	while (**input != 'x' - 32 * caps)
		(*input)++;
	(*input)++;
	return ((fd.width < fd.len ? fd.len : fd.width) + (fd.pound * 2));
}

int	ft_printf_x_nocap(char **input, va_list ap)
{
	return (ft_printf_x(input, ap, 0));
}

int	ft_printf_x_cap(char **input, va_list ap)
{
	return (ft_printf_x(input, ap, 1));
}
