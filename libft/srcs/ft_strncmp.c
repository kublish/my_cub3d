/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:09:41 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/23 18:37:34 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned long n)
{
	while (*s1 && n)
	{
		if (*s2 == 0)
			return ((unsigned char)*s1);
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (-(unsigned char)*s2);
}
