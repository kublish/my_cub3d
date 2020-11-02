/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:58:56 by zacharyku         #+#    #+#             */
/*   Updated: 2020/10/31 17:20:31 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"

void render_line(t_dpoint *ray_dir, t_data *data, x)
{
	int         y;
	int         is_NS;
	t_dpoint    hit;

	ray_cast(ray_dir, &hit, &is_NS);
	y = 0;
	while (y < data->res.y)
	{
			mlx_pixel_put(data->mlx_ptr, data->win, x, y++, x);
	}  
}

void render_screen(t_data *d)
{
	int i;
	double      planeStart;
	t_dpoint    ray_dir;

	planeStart = d->cam.plane * -.5;
	i = 0;
	while (i < d->res.x)
    {
        perp_vec(&d->cam.dir, (i + 1.0) / d->res.x * d->cam.plane, &raydir);
        render_line(&ray_dir, data, i);
    }
}
