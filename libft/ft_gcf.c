/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:36:54 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/22 12:47:24 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns the greatest common factor between a and b
*/

static int	get_factor(int a, int b)
{
	int i;

	if (a == b)
		return (a);
	if (a % 2 == 0 && b % 2 == 0)
		return (2);
	i = 3;
	while (a % i != 0 || b % i != 0)
		if (2 * i > a && 2 * i > b)
			return (1);
		else
			i += 2;
	return (i);
}

int			ft_gcf(int a, int b)
{
	int result;
	int factor;

	result = 1;
	factor = get_factor(a, b);
	while (factor != 1)
	{
		a /= factor;
		b /= factor;
		result *= factor;
		factor = get_factor(a, b);
	}
	return (result);
}
