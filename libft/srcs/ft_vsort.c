/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:16:51 by zkubli            #+#    #+#             */
/*   Updated: 2019/12/17 02:52:49 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_vsort(t_vector *vect, int (*f)(void *, void *))
{
	size_t	start;
	size_t	lowest;
	size_t	compare;

	start = 0;
	while (start + 1 < vect->count)
	{
		lowest = start;
		compare = start;
		while (++compare < vect->count)
			if (f(ft_vget(vect, lowest), ft_vget(vect, compare)) < 0)
				lowest = compare;
		ft_vswap(vect, lowest, start);
		start++;
	}
}
