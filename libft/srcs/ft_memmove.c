/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:07:53 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/22 12:48:38 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*my_dst;
	unsigned char	*my_src;

	my_dst = (unsigned char *)dst;
	my_src = (unsigned char *)src;
	if (my_src != my_dst)
	{
		if (my_src < my_dst)
			while (len--)
				*(my_dst + len) = *(my_src + len);
		else
		{
			i = -1;
			while (++i < len)
				*(my_dst + i) = *(my_src + i);
		}
	}
	return (dst);
}
