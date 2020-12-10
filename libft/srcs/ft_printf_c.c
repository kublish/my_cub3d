/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 07:25:22 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 16:22:50 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "get_format.h"
#include "helper.h"
#include "printer.h"

int	ft_printf_c(char **input, va_list ap)
{
	t_format_data	fd;
	int				out;
	char			mychar;

	get_format(input, &fd, ap);
	while (**input != 'c')
		(*input)++;
	(*input)++;
	mychar = va_arg(ap, int);
	out = 1;
	if (!(fd.minus))
		out += loop_char(' ', fd.width - 1);
	buffer(NULL, 0);
	write(1, &mychar, 1);
	if (fd.minus)
		out += loop_char(' ', fd.width - 1);
	return (out);
}
