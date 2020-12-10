/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdoublecap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 02:46:09 by zkubli            #+#    #+#             */
/*   Updated: 2019/12/17 02:51:34 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

void	ft_vdoublecap(t_vector *vect)
{
	void *newdata;

	vect->capacity *= 2;
	newdata = malloc(vect->capacity * vect->elem_size);
	ft_memcpy(newdata, vect->data, vect->count * vect->elem_size);
	ft_memdel(&(vect->data));
	vect->data = newdata;
}
