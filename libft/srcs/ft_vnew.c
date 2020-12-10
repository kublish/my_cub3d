/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:11:27 by zkubli            #+#    #+#             */
/*   Updated: 2019/12/17 02:52:13 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

t_vector	*ft_vnew(size_t elem_size)
{
	t_vector *my_vector;

	my_vector = malloc(sizeof(t_vector));
	my_vector->elem_size = elem_size;
	my_vector->capacity = 1;
	my_vector->count = 0;
	my_vector->data = malloc(elem_size);
	return (my_vector);
}
