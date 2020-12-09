/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:03:28 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/22 16:27:56 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** flags based on bits (Next time do a bitfield struct)
** 001: '+'				(and put all the relvant data in it)
** 002: '-'
** 004: ' '
** 008: '0'
** 016: 'h'
** 032: 'hh'
** 064: 'l'
** 128: 'll'
** 256	'#'
*/

#include <stdarg.h>
#include "get_format.h"
#include "helper.h"

static void	get_flags(char *input, t_format_data *fd)
{
	int i;

	i = -1;
	while (!(is_spec(input[++i])))
		if (input[i] == '+')
			fd->plus = 1;
		else if (input[i] == '-')
			fd->minus = 1;
		else if (input[i] == ' ')
			fd->space = 1;
		else if (input[i] == '0' && (i <= 0 || ((input[i - 1] < '0' ||
						input[i - 1] > '9') && input[i - 1] != '.')))
			fd->zero = 1;
		else if (input[i] == 'h' && !(fd->h) && !(fd->hh))
			fd->h = 1;
		else if (input[i] == 'h' && (fd->h = 0) == 0)
			fd->hh = 1;
		else if (input[i] == 'l' && !(fd->l) && !(fd->ll))
			fd->l = 1;
		else if (input[i] == 'l' && (fd->l = 0) == 0)
			fd->ll = 1;
		else if (input[i] == '#')
			fd->pound = 1;
		else if (input[i] == 'L')
			fd->big_l = 1;
}

static void	get_width(char **input, t_format_data *fd, va_list ap)
{
	int	res;

	res = 0;
	while (!(is_spec(**input) || **input == '.'))
		if (is_flag(**input))
			(*input)++;
		else
		{
			if (**input == '*')
			{
				res = (va_arg(ap, int));
				(*input)++;
			}
			if (**input <= '9' && **input >= '0')
				res = (my_atoi(input));
			break ;
		}
	if (res < 0)
	{
		res *= -1;
		fd->minus = 1;
	}
	while (!(is_spec(**input) || **input == '.'))
		(*input)++;
	fd->width = res;
}

static int	get_precision(char **input, va_list ap)
{
	int res;

	(*input)++;
	res = 0;
	if (**input == '*')
	{
		res = (va_arg(ap, int));
		(*input)++;
	}
	if (**input <= '9' && **input >= '0')
		res = (my_atoi(input));
	if (res < 0)
		return (-1);
	return (res);
}

/*
**	probably possible to cram into one func, but not worth.
*/

void		get_format(char **input, t_format_data *fd, va_list ap)
{
	*(int *)fd = 0;
	get_flags(*input, fd);
	get_width(input, fd, ap);
	while (**input != '.' && !is_spec(**input))
		(*input)++;
	if (**input == '.')
		fd->prec = get_precision(input, ap);
	else
		fd->prec = -1;
}
