/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 04:15:03 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 14:27:34 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "helper.h"
#include "printer.h"
#include "get_format.h"

int	ft_printf_o(char **input, va_list ap)
{
	t_format_data	fd;
	t_ull			val;

	fd.base = 8;
	get_format(input, &fd, ap);
	val = read_arg(ap, &fd);
	if (val == 0 && fd.prec != 0)
		fd.pound = 0;
	fd.width -= (fd.pound);
	fd.prec -= (fd.pound) * (fd.prec > 0);
	fd.len = numlen(val, fd.base, fd.prec);
	if (!((fd.zero && fd.prec == -1) || fd.minus))
		loop_char(' ', fd.width - fd.len);
	if (fd.pound)
		buffer("0", 1);
	if (fd.zero && fd.prec == -1 && !(fd.minus))
		loop_char('0', fd.width - fd.len);
	my_putnbr_base(val, fd.prec, &fd);
	if (fd.minus)
		loop_char(' ', fd.width - fd.len);
	while (**input != 'o')
		(*input)++;
	(*input)++;
	return ((fd.width < fd.len ? fd.len : fd.width) + (fd.pound));
}
