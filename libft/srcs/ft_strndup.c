/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:57:47 by zkubli            #+#    #+#             */
/*   Updated: 2020/02/10 08:12:06 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char	*strndup(const char *s1, size_t n)
{
	char	*re_val;
	int		lesser_size;
	int		i;

	lesser_size = ft_strlen(s1);
	lesser_size = (lesser_size < n ? lesser_size : n);
	re_val = malloc(sizeof(char) * (lesser_size + 1));
	i = 0;
	while (i < lesser_size)
	{
		re_val[i] = s1[i];
		i++;
	}
	re_val[i] = '\0';
	return (re_val);
}
