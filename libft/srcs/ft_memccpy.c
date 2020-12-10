/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:07:27 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/20 19:58:10 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void *re_val;

	re_val = dst;
	while (n--)
		if ((*(unsigned char *)(src)) == (unsigned char)(c))
		{
			*(unsigned char *)(dst++) = *(unsigned char *)src;
			return (dst);
		}
		else
			*(unsigned char *)(dst++) = *(unsigned char *)(src++);
	return (NULL);
}
