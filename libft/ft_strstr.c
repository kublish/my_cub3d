/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:10:32 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/21 11:32:49 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t index;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		index = 0;
		while (needle[index] && needle[index] == haystack[index])
			index++;
		if (!(needle[index]))
			return ((char *)(haystack));
		haystack++;
	}
	return (NULL);
}
