/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 10:22:11 by zacharyku         #+#    #+#             */
/*   Updated: 2020/08/17 16:07:21 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_strappend(char **s1, char *s2)
{
	char *old_str;
	
	old_str = *s1;
	*s1 = ft_strjoin(*s1, s2);
	free(old_str);
}
