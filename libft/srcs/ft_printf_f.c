/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:45:30 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 16:25:56 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "helper.h"
#include "printer.h"
#include "get_format.h"
#include "string_math.h"

char	*my_dtoa(va_list ap)
{
	static char	data[MAX_DIG];
	int			i;
	t_floatcast	d;

	i = 0;
	while (i < MAX_DIG)
		data[i++] = '\0';
	d.d = va_arg(ap, double);
	if ((d.s_parts.sign = (d.d < 0)))
		data[0] = '-';
	data[d.s_parts.sign + 1] = '.';
	i = 0;
	while (i < 52)
	{
		data[d.s_parts.sign] = ((d.s_parts.mantissa >> i++ & 1) ? '1' : '0');
		a_half(data + d.s_parts.sign);
	}
	data[d.s_parts.sign] = '0' + !!(d.s_parts.exponent);
	i = d.s_parts.exponent - 1023;
	while (i != 0)
		if (i-- > 0)
			a_double(data + d.s_parts.sign);
		else if ((i += 2) < 1)
			a_half(data + d.s_parts.sign);
	return (data);
}

char	*my_ldtoa(va_list ap)
{
	static char	data[MAX_DIG];
	int			i;
	t_longdcast	d;

	i = 0;
	while (i < MAX_DIG)
		data[i++] = '\0';
	d.d = va_arg(ap, long double);
	if (d.s_parts.sign)
		data[0] = '-';
	data[d.s_parts.sign + 1] = '.';
	i = 0;
	while (i < 63)
	{
		data[d.s_parts.sign] = ((d.s_parts.mantissa >> i++ & 1) ? '1' : '0');
		a_half(data + d.s_parts.sign);
	}
	data[d.s_parts.sign] = '0' + !!(d.s_parts.exponent);
	i = d.s_parts.exponent - 16383;
	while (i != 0)
		if (i-- > 0)
			a_double(data + d.s_parts.sign);
		else if ((i += 2) < 1)
			a_half(data + d.s_parts.sign);
	return (data);
}

int		numlen_f(char *data, t_format_data *fd)
{
	int i;

	i = 0;
	while (data[i] && data[i] != '.')
		i++;
	if (*data == '-')
		i--;
	if (fd->prec || fd->pound)
		i++;
	i += (fd->prec < 0 ? -fd->prec : fd->prec);
	return (i);
}

int		ft_printf_f(char **input, va_list ap)
{
	t_format_data	fd;
	char			*data;

	get_format(input, &fd, ap);
	fd.prec = fd.prec == -1 ? -6 : fd.prec;
	data = fd.big_l ? my_ldtoa(ap) : my_dtoa(ap);
	fd.len = numlen_f(data, &fd);
	fd.width -= (*data == '-') || fd.plus || fd.space;
	if (!((fd.zero && fd.prec < 0) || fd.minus))
		loop_char(' ', fd.width - fd.len);
	if (*data != '-' && (fd.plus || fd.space))
		buffer(fd.plus ? "+" : " ", 1);
	if (fd.prec < 0 && fd.zero && !(fd.minus))
		loop_char('0', fd.width - fd.len);
	a_round(data, (fd.prec < 0 ? -fd.prec : fd.prec));
	buffer(data, fd.len + (*data == '-'));
	if (fd.minus)
		loop_char(' ', fd.width - fd.len);
	while (**input != 'f')
		(*input)++;
	(*input)++;
	return ((fd.width < fd.len ? fd.len : fd.width) +
			(fd.space || fd.plus || *data == '-'));
}
