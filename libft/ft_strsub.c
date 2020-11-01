/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:51:45 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/23 13:34:49 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *mysub;

	if (!(s))
		return (NULL);
	if (!(mysub = (char *)(malloc((len + 1) * sizeof(char)))))
		return (NULL);
	ft_strncpy(mysub, s + start, len);
	mysub[len] = '\0';
	return (mysub);
}
