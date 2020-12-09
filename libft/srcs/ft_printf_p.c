/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 02:37:45 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 15:13:52 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "get_format.h"
#include "printer.h"
#include "helper.h"
#include "ft_printf.h"

int	ft_printf_p(char **input, va_list ap)
{
	t_format_data	fd;
	t_ull			val;

	fd.base = 16;
	get_format(input, &fd, ap);
	fd.ll = 1;
	fd.zero = 1;
	val = read_arg(ap, &fd);
	fd.len = numlen(val, fd.base, fd.prec);
	if (fd.prec == -1)
		fd.prec = 1;
	fd.width -= 2;
	if (!((fd.zero && fd.prec == -1) || fd.minus))
		loop_char(' ', fd.width - fd.len);
	buffer("0x", 2);
	if (fd.zero && fd.prec == -1 && !(fd.minus))
		loop_char('0', fd.width - fd.len);
	my_putnbr_base(val, fd.prec, &fd);
	if (fd.minus)
		loop_char(' ', fd.width - fd.len);
	while (**input != 'p')
		(*input)++;
	(*input)++;
	return ((fd.width < fd.len ? fd.len : fd.width) + 2);
}
