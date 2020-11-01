/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:07:43 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/26 10:45:26 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *re_val;

	re_val = dst;
	while (dst != src && n--)
		*(unsigned char *)(dst++) = *(unsigned char *)(src++);
	return (re_val);
}
