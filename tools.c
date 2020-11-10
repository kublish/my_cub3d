/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:16:49 by zacharyku         #+#    #+#             */
/*   Updated: 2020/11/10 12:29:35 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

int     is_player(const char a)
{
	return  (a == 'N' || a == 'S' || a == 'E' || a == 'W');
}

/*
**  perp_distance provides the point perpendicular to the end of vec, at
**  distance relative to size of vec. positive ratio is to the right.
*/

void    ray_init(t_data *d, double ratio)
{
	d->ray.dir.x = d->cam.dir.y * ratio + d->cam.dir.x; 
	d->ray.dir.y = -d->cam.dir.x * ratio + d->cam.dir.y;
    d->ray.hit.x = (int)d->cam.player.x;
    d->ray.hit.y = (int)d->cam.player.y;
    d->ray.inc.x = (d->ray.dir.x < 0 ? -1 : 1);
    d->ray.inc.y = (d->ray.dir.y < 0 ? -1 : 1);
	if (d->ray.dir.x < 0)
		d->ray.sideDist.x = d->cam.player.x - d->ray.hit.x;
	else
		d->ray.sideDist.x = d->ray.hit.x - d->cam.player.x;
	if (d->ray.dir.y < 0)
		d->ray.sideDist.y = d->cam.player.y - d->ray.hit.y;
	else
		d->ray.sideDist.y = d->ray.hit.y - d->cam.player.y;
	d->ray.deltaDist.x = (d->ray.dir.x ? abs (1 / d->ray.dir.x) 	: ); 
}

int     ray_cast(t_data *d, double percentage)
{

    int     hit_found;
	
}
