/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:08:53 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/26 11:03:33 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	if ((cpy = (char *)(malloc((ft_strlen(s1) + 1) * sizeof(char)))))
	{
		i = 0;
		while (*(s1 + i))
		{
			*(cpy + i) = *(s1 + i);
			i++;
		}
		*(cpy + i) = '\0';
		return (cpy);
	}
	else
		return (NULL);
}
