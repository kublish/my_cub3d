/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:25:29 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/23 13:53:44 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	const char *nstr;
	const char *strend;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!(*s))
		return (ft_strnew(0));
	strend = NULL;
	nstr = s;
	while (*s)
		if (*s == ' ' || *s == '\n' || *s == '\t')
		{
			strend = s - 1;
			while (*s == ' ' || *s == '\n' || *s == '\t')
				s++;
			if (*s)
				strend = NULL;
		}
		else
			s++;
	if (strend == NULL)
		strend = s - 1;
	return (ft_strsub(nstr, 0, (unsigned int)(strend - nstr + 1)));
}
