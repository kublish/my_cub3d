/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:56:11 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/22 13:14:06 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *memptr;

	if (!(memptr = (char *)(malloc(size + 1))))
		return (NULL);
	while (size--)
		*(memptr + size) = 0;
	*memptr = 0;
	return (memptr);
}
