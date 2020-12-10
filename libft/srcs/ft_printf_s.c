/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:13:41 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 16:09:40 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "get_format.h"
#include "helper.h"
#include "printer.h"
#include "ft_printf.h"

static int	my_strlen(char *strlen)
{
	int i;

	i = 0;
	while (strlen[i])
		i++;
	return (i);
}

void		str_assign(char *str, const char *read)
{
	int i;

	i = 0;
	while (read[i])
	{
		str[i] = read[i];
		i++;
	}
}

int			ft_printf_s(char **input, va_list ap)
{
	t_format_data	fd;
	char			nullval[7];
	char			*str;

	str_assign(nullval, "(null)");
	get_format(input, &fd, ap);
	while (**input != 's')
		(*input)++;
	(*input)++;
	str = (char *)(va_arg(ap, long int));
	if (!(str))
		str = nullval;
	fd.len = my_strlen(str);
	fd.width -= ((fd.len < fd.prec || fd.prec == -1) ? fd.len : fd.prec);
	if (!(fd.minus))
		return (loop_char(' ', fd.width) + my_putstr(str, fd.prec));
	else
		return (my_putstr(str, fd.prec) + loop_char(' ', fd.width));
}
