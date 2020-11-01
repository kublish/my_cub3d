/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:52:32 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/24 15:30:21 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		i;

	if (!(s) || !(f) || !(map = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(map + i) = f(i, *(s + i));
		i++;
	}
	*(map + i) = '\0';
	return (map);
}
