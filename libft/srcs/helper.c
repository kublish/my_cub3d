/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:04:22 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 15:15:45 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include "helper.h"
#include "get_format.h"

int			is_flag(char c)
{
	return (c == '+' || c == '-' || c == ' ' || c == '0'
			|| c == 'h' || c == 'l' || c == '#' || c == 'L');
}

int			is_spec(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == '%' ||
			c == 'f');
}

int			my_atoi(char **s)
{
	int		i;

	while (is_flag(**s))
		(*s)++;
	i = 0;
	while (**s != '\0' && **s >= '0' && **s <= '9')
		i = i * 10 + *((*s)++) - '0';
	return (i);
}

int			numlen(t_ull num, int base, int prec)
{
	int diglen;

	base = (base < 0 ? -base : base);
	diglen = 0;
	while (num != 0)
	{
		num /= base;
		diglen++;
	}
	prec = (prec < 0 ? -prec : prec);
	return (prec < diglen ? diglen : prec);
}

t_ull		read_arg(va_list ap, t_format_data *fd)
{
	long long	temp;
	t_ull		res;

	if (fd->ll)
		temp = (va_arg(ap, long long));
	else if (fd->l)
		temp = (va_arg(ap, long));
	else if (fd->h)
		temp = (short)(va_arg(ap, int));
	else if (fd->hh)
		temp = (char)(va_arg(ap, int));
	else
		temp = (va_arg(ap, int));
	fd->isneg = (temp < 0 && fd->base < 0);
	res = (fd->base < 0 && temp < 0 ? -temp : temp);
	if (fd->base > 0 && temp < 0 && !(fd->ll))
	{
		if (fd->hh || fd->h)
			res += (fd->hh ? UCHAR_MAX : USHRT_MAX) + 1;
		else
			res += (fd->l ? ULONG_MAX : UINT_MAX) + 1;
	}
	return (res);
}
