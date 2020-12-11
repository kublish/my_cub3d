/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vinsert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 11:34:01 by zkubli            #+#    #+#             */
/*   Updated: 2020/12/09 21:26:03 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_vinsert(t_vector *vect, void *elem, size_t index)
{
	if (!(vect))
		return ;
	vect->count++;
	if (vect->count >= vect->capacity)
		ft_vdoublecap(vect);
	ft_memmove(vect->data + (index + 1) * vect->elem_size,
			vect->data + index * vect->elem_size,
			(vect->count++ - index) * vect->elem_size);
	ft_memmove(vect->data + index * vect->elem_size,
			elem, vect->elem_size);
}
