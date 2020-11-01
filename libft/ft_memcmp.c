/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:07:38 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/23 18:39:07 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else
		{
			s1++;
			s2++;
		}
	return (0);
}
