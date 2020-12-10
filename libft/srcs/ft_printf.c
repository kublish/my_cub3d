/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 00:10:28 by zkubli            #+#    #+#             */
/*   Updated: 2020/03/11 06:57:54 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "printer.h"
#include "get_format.h"

static t_specf g_spec_functions[50] =
{
	{'c', ft_printf_c},
	{'s', ft_printf_s},
	{'p', ft_printf_p},
	{'d', ft_printf_d},
	{'i', ft_printf_d},
	{'o', ft_printf_o},
	{'u', ft_printf_u},
	{'x', ft_printf_x_nocap},
	{'X', ft_printf_x_cap},
	{'f', ft_printf_f},
	{'%', ft_printf_percent},
	{'\0', NULL}
};

int	ft_printf_percent(char **input, va_list ap)
{
	t_format_data fd;

	get_format(input, &fd, ap);
	while (**input != '%')
		(*input)++;
	(*input)++;
	if (fd.minus)
		return (buffer("%", 1) + loop_char(' ', fd.width - 1));
	else
		return (loop_char(' ', fd.width - 1) + buffer("%", 1));
}

int	specifier(char **input, va_list ap)
{
	int i;
	int j;

	input[0]++;
	i = -1;
	while (input[0][++i])
	{
		j = 0;
		while (g_spec_functions[j].c != '\0')
			if (g_spec_functions[j].c == input[0][i])
				return (g_spec_functions[j].f(input, ap));
			else
				j++;
	}
	return (0);
}

int	ft_printf(char *input, ...)
{
	va_list	ap;
	int		printed;

	printed = 0;
	va_start(ap, input);
	while (input && *input)
		if (*input != '%')
		{
			buffer(input++, 1);
			printed++;
		}
		else
			printed += specifier(&input, ap);
	va_end(ap);
	buffer(NULL, 0);
	return (printed);
}
