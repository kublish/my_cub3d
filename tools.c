/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:16:49 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/09 14:40:10 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cub3d.h"

int     is_player(const char a)
{
	return  (a == 'N' || a == 'S' || a == 'E' || a == 'W');
}

int	sprite_cmp(void *a, void *b)
{
	if ((*((t_sprite **)(a)))->dist < ((*((t_sprite **)(b))))->dist)
		return (-1);
	else
		return (1);
}

void	destroy_sprites(t_data *d)
{
	int i;

	i = 0;
	while (i < d->sprites->count)
	{
		fprintf(stderr, "destroying %d\n", i);
		free(((t_sprite **)(d->sprites->data))[i++]);
	}
	ft_vdestroy(d->sprites);
}
