/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 03:02:11 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 16:18:49 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include "get_format.h"
#include "helper.h"
#include "printer.h"

/*
** If I had made a struct for all my output data, I would have saved two
** variables. I could have used one of those to manage this struct and making
** it like 5x as readable.
**
** (It was too ugly, I ended up fixin' it)
**
** This should jog your memory
**
** Spaces Sign Zeros Number Spaces
**   A		A			A
**	 		B	B		B
**	 		C			C	  C
**
**
** As of now I am using prec == -1 && flag & 8 (precision uninit and flag 0)
** to indicate the case of 'B'. And flag & 2 (flag -) to indicate the case of
** C. Case A is default;
*/

int					ft_printf_d(char **input, va_list ap)
{
	t_format_data	fd;
	t_ull			val;

	fd.base = -10;
	get_format(input, &fd, ap);
	val = read_arg(ap, &fd);
	fd.len = numlen(val, fd.base, fd.prec);
	fd.width -= (fd.isneg || fd.plus || fd.space);
	if (!((fd.zero && fd.prec == -1) || fd.minus))
		loop_char(' ', fd.width - fd.len);
	if (fd.isneg)
		buffer("-", 1);
	else if (fd.plus || fd.space)
		buffer(fd.plus ? "+" : " ", 1);
	if (fd.prec == -1 && fd.zero && !(fd.minus))
		loop_char('0', fd.width - fd.len);
	my_putnbr_base(val, fd.prec, &fd);
	if (fd.minus)
		loop_char(' ', fd.width - fd.len);
	while (**input != 'd' && **input != 'i')
		(*input)++;
	(*input)++;
	return ((fd.width < fd.len ? fd.len : fd.width) +
			(fd.space || fd.plus || fd.isneg));
}
