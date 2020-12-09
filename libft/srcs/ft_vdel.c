/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:41:07 by zkubli            #+#    #+#             */
/*   Updated: 2019/12/17 02:49:59 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_vdel(t_vector *vect, size_t index)
{
	if (index < --(vect->count) && vect->count > 0)
	{
		ft_memmove(
				vect->data + (index * vect->elem_size),
				vect->data + (index + 1 * vect->elem_size),
				(index - vect->count) * vect->elem_size);
	}
}
