/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 04:45:40 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 16:26:41 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"
#include "get_format.h"
#include "printer.h"
#include "helper.h"

int	ft_printf_b(char **input, va_list ap)
{
	t_format_data		fd;
	unsigned long long	val;

	get_format(input, &fd, ap);
	val = read_arg(ap, &fd);
	fd.len = numlen(val, 2, fd.prec);
	if (!(fd.minus))
		loop_char(fd.zero ? '0' : ' ', fd.width - fd.len);
	my_putnbr_base(val, fd.prec, &fd);
	if (fd.minus)
		loop_char(' ', fd.width - fd.len);
	while (**input != 'b')
		(*input)++;
	(*input)++;
	return (fd.width < fd.len ? fd.len : fd.width);
}