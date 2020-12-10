/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:27:43 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/22 20:35:52 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "printer.h"
#include "get_format.h"

#define BUFF_MAX 512

static char g_lnum[16] =
{'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'a', 'b', 'c', 'd', 'e', 'f'};

static char g_unum[16] =
{'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};

int	buffer(const char *to_add, int d)
{
	static char buff[BUFF_MAX];
	static int	i;
	int			len;
	int			j;

	j = 0;
	len = 0;
	while (to_add && len < d && to_add[len] != '\0')
		len++;
	if (d < 0)
		d = 0;
	if (to_add && len + i < BUFF_MAX)
	{
		len += i;
		while (i < len)
			buff[i++] = to_add[j++];
	}
	else
	{
		write(1, buff, i);
		write(1, to_add, len);
		i = 0;
	}
	loop_char('0', d - (len - (i - j)));
	return (d);
}

int	my_putstr(const char *str, int precision)
{
	int i;

	i = -1;
	while (str[++i] && (precision == -1 || precision-- > 0))
		buffer(str + i, 1);
	return (i);
}

int	my_putnbr_base(t_ull num, int prec, t_format_data *fd)
{
	unsigned int	output;

	prec = (prec < 0 ? -prec : prec);
	fd->base = (fd->base < 0 ? -fd->base : fd->base);
	output = 0;
	if (num >= (unsigned int)(fd->base < 0 ? -fd->base : fd->base))
		output += my_putnbr_base(num / fd->base, prec - !!(prec), fd);
	else
		while (prec > 1)
		{
			output += buffer("0", 1);
			prec--;
		}
	if (prec > 0 || num != 0)
		output += buffer((fd->caps ? g_unum : g_lnum) + num % fd->base, 1);
	return (output);
}

int	loop_char(char c, int i)
{
	int output;

	output = 0;
	while (i > output)
		output += buffer(&c, 1);
	return (output);
}
