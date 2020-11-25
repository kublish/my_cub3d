/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:58:56 by zacharyku         #+#    #+#             */
/*   Updated: 2020/11/25 00:08:22 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"

void render_col(t_data *data, int x)
{
	int         y;
	int         is_NS;
	t_dpoint    hit;

	y = 0;
	while (y < data->res.y)
	{
			mlx_pixel_put(data->mlx_ptr, data->win, x, y++, x);
	}  
}

void render_screen(t_data *d)
{
	int			i;
	double		planeStart;

	planeStart = d->cam.plane * -.5;
	i = 0;
	while (i < d->res.x)
    {
        ray_init(d, (i + 1.0) / d->res.x * d->cam.plane);
        ray_cast(d);
		render_col(d, i);
    }
}
