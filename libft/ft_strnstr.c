/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:10:15 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/23 09:25:43 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t index;

	if (*needle == '\0')
		return ((char *)haystack);
	index = 0;
	while (*haystack && n--)
	{
		index = 0;
		while (needle[index] && index <= n && needle[index] == haystack[index])
			index++;
		if (!(needle[index]))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
