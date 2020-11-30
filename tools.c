/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:16:49 by zacharyku         #+#    #+#             */
/*   Updated: 2020/11/30 11:43:05 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

int     is_player(const char a)
{
	return  (a == 'N' || a == 'S' || a == 'E' || a == 'W');
}

void    ray_init(t_data *d, double ratio)
{
	d->ray.dir.x = d->cam.dir.y * ratio + d->cam.dir.x; 
	d->ray.dir.y = -d->cam.dir.x * ratio + d->cam.dir.y;
    d->ray.hit.x = (int)d->cam.player.x;
    d->ray.hit.y = (int)d->cam.player.y;
    d->ray.inc.x = (d->ray.dir.x < 0 ? -1 : 1);
    d->ray.inc.y = (d->ray.dir.y < 0 ? -1 : 1);
	d->ray.deltaDist.x = (d->ray.dir.x ? fabs(1 / d->ray.dir.x) : 0);
	d->ray.deltaDist.y = (d->ray.dir.y ? fabs(1 / d->ray.dir.y) : 0);
	//somthing fishy on these edge cases w hit = player and dir = 0
	if (d->ray.dir.x < 0)
		d->ray.sideDist.x = d->cam.player.x - d->ray.hit.x;
	else
		d->ray.sideDist.x = d->ray.hit.x - d->cam.player.x + 1.0;
	if (d->ray.dir.y < 0)
		d->ray.sideDist.y = d->cam.player.y - d->ray.hit.y;
	else
		d->ray.sideDist.y = d->ray.hit.y - d->cam.player.y + 1.0; 
	d->ray.sideDist.y *= d->ray.deltaDist.y;
	d->ray.sideDist.x *= d->ray.deltaDist.x;
}

int		check_map(t_data *d, t_point *p)
{
	if (p->x > d->map.rowlen || p->x < 0 ||
			p->y * d->map.rowlen > d->map.tablelen || p->y < 0)
		return (-1);
	return (d->map.table[p->x + p->y *d->map.rowlen]);
}

double	ray_cast(t_data *d)
{
    int     hit_found;
	int		side;

	hit_found = 0;
	while (!hit_found)
	{
		if (d->ray.sideDist.x && d->ray.sideDist.x < d->ray.sideDist.y)
		{
			d->ray.sideDist.x += d->ray.deltaDist.x;
			d->ray.hit.x += d->ray.inc.x;
			d->ray.is_NS = 1;
		}
		else
		{
			d->ray.sideDist.y += d->ray.deltaDist.y;
			d->ray.hit.y += d->ray.inc.y;
			d->ray.is_NS = 1;
		}
		if (check_map(d, &d->ray.hit) == 1)
			hit_found = 1;
	}
	if (d->ray.is_NS)
		return ((d->ray.sideDist.y - d->ray.deltaDist.y) / d->ray.dir.y); 
	else
		return ((d->ray.sideDist.x - d->ray.deltaDist.x) / d->ray.dir.x); 
}
