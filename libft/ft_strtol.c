/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:32:03 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/24 15:52:08 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_to_val(char c)
{
	if (c <= '9' && c >= '0')
		return (c - '0');
	if (c <= 'Z' && c >= 'A')
		return (c - 'A' + 11);
	if (c <= 'z' && c >= 'a')
		return (c - 'a' + 11);
	return (-1);
}

static void	handle_prefix(const char **s, int *b)
{
	char *st;

	st = (char *)*s;
	if (*st == '0' && st[1] == '0' && st[2] == 'x' && (*b == 0 || *b == 16))
	{
		*b = 16;
		st += 3;
	}
	else if (*st == 0 && st[1] == 'x' && (*b == 0 || *b == 16))
	{
		*b = 8;
		st += 2;
	}
	else if (*b == 0)
		*b = 10;
}

long		ft_strtol(const char *s, char **endptr, int b)
{
	long	i;
	int		factor;

	if (endptr)
		*endptr = (char *)s;
	i = 0;
	while (ft_isspace(*s))
		s++;
	factor = 1 - ((*s == '-') * 2);
	s += (*s == '+' || *s == '-');
	handle_prefix(&s, &b);
	while (char_to_val(*s) != -1 && char_to_val(*s) < b)
	{
		i *= b;
		i += char_to_val(*s);
		s++;
		if (endptr)
			*endptr = (char *)s;
		if (i < 0)
			return (0 - (factor > 0));
	}
	return (i * factor);
}
