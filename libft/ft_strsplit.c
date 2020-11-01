/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:03:19 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/24 15:37:15 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_strsplit_alen(char const *s, char c)
{
	int arrlen;

	arrlen = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		arrlen += (*s != '\0');
		while (*s && *s != c)
			s++;
	}
	return (arrlen + 1);
}

static int	ft_strsplit_wrdlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		strlen;
	char	**re_val;

	if (!(s) || !(re_val = (char **)(malloc((
							ft_strsplit_alen(s, c) * sizeof(char *))))))
		return (NULL);
	i = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		strlen = ft_strsplit_wrdlen(s, c);
		re_val[i] = ft_strsub(s, 0, strlen);
		s += strlen;
		while (*s == c)
			s++;
		i++;
	}
	re_val[i] = NULL;
	return (re_val);
}
