/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:08:31 by zkubli            #+#    #+#             */
/*   Updated: 2020/01/25 16:45:37 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t index;

	index = 0;
	while (*(src + index))
	{
		*(dst + index) = *(src + index);
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
