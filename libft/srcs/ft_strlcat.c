/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:09:04 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/23 12:26:41 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dsti;
	size_t srci;
	size_t i;

	dsti = 0;
	while (dst[dsti] != '\0')
		dsti++;
	srci = 0;
	while (src[srci] != '\0')
		srci++;
	i = 0;
	i += dsti;
	while (i + 1 < dstsize && i < dsti + srci)
	{
		dst[i] = src[i - dsti];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	if (dsti > dstsize)
		dsti = dstsize;
	return (dsti + srci);
}
