/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:09:49 by zkubli            #+#    #+#             */
/*   Updated: 2020/01/29 15:19:38 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t index;

	index = 0;
	while (*(src + index) && index < len)
	{
		*(dst + index) = *(src + index);
		index++;
	}
	while (index < len)
		*(dst + index++) = '\0';
	return (dst);
}
