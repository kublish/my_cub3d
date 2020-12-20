/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:00:19 by zkubli            #+#    #+#             */
/*   Updated: 2020/12/10 11:20:33 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/*
** consider switching this to a byte by byte to avoid malloc call
** and speed up swap
*/

void	ft_vswap(t_vector *vect, size_t a, size_t b)
{
	void *temp;

	if (!(vect) || a == b)
		return ;
	a *= vect->elem_size;
	b *= vect->elem_size;
	temp = malloc(vect->elem_size);
	ft_memcpy(temp, vect->data + a, vect->elem_size);
	ft_memcpy(vect->data + a, vect->data + b, vect->elem_size);
	ft_memcpy(vect->data + b, temp, vect->elem_size);
	ft_memdel(&temp);
}
