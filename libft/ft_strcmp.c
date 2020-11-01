/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:08:26 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/23 18:35:22 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s2 == 0)
			return ((unsigned char)*s1);
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
	}
	return (-(unsigned char)(*s2));
}
