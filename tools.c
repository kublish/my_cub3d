/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:16:49 by zacharyku         #+#    #+#             */
/*   Updated: 2020/11/02 22:35:06 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     is_player(const char a)
{
	return  (a == 'N' || a == 'S' || a == 'E' || a == 'W');
}

/*
**  perp_distance provides the point perpendicular to the end of vec, at
**  distance relative to size of vec. positive ratio is to the right.
*/

void    ray_cast_init(t_data *d, double percentge)
{
	d->ray.dir.x = d->cam.dir.y; 
    d->ray.hit.x = (int)d->cam.player.x;
    d->ray.hit.y = (int)d->cam.player.y;
    d->ray.inc.y = (d->ray.dir.y < 0 ? -1 : 1);
    d->ray.inc.x = (d->ray.dir.x < 0 ? -1 : 1);
}

int     ray_cast(t_data *d, )
{

    int     hit_found;
    //ft_memcpy(hit, )
}
