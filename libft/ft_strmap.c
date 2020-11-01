/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:22:43 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/24 14:33:18 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	int		i;

	if (!(s) || !(map = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(map + i) = f(*(s + i));
		i++;
	}
	map[i] = '\0';
	return (map);
}
