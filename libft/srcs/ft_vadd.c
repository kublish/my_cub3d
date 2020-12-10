/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:43:17 by zkubli            #+#    #+#             */
/*   Updated: 2019/12/17 02:49:04 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_vadd(t_vector *vect, void *elem)
{
	if (vect->count >= vect->capacity)
		ft_vdoublecap(vect);
	ft_memmove(vect->data + (vect->count++ * vect->elem_size),
			elem, vect->elem_size);
	return (vect->count - 1);
}
