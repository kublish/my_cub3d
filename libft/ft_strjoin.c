/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:07:59 by zkubli            #+#    #+#             */
/*   Updated: 2020/08/17 15:08:22 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;

	if (!(s1) || !(s2))
		return (NULL);
	if (!(newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1)
		newstr[i++] = *(s1++);
	while (*s2)
		newstr[i++] = *(s2++);
	newstr[i] = '\0';
	return (newstr);
}
