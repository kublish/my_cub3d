/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:58:56 by zacharyku         #+#    #+#             */
/*   Updated: 2020/11/29 22:05:34 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "cub3d.h"

void render_col(t_data *data, int x, double perp_dist)
{
	int	wall_start;
	int	wall_end;
	int y;
	int color;

	wall_start = (int)((data->res.y - data->res.y / perp_dist) / 2);
	wall_end = (int)ceil((data->res.y + data->res.y / perp_dist) / 2);
	y = 0;
	while (y < data->res.y)
	{
			if (y < wall_start)
				color = 0x00BB11F0;
			else if (y > wall_end)
				color = 0x00F011BB;
			else
				color = 0x0011F0BB;
			mlx_pixel_put(data->mlx_ptr, data->win, x, y++, color);
	}  
}

void render_screen(t_data *d)
{
	int			i;
	double		perp_dist;

	i = 0;
	while (i < d->res.x)
    {
        ray_init(d, (i + 1.0) / d->res.x * d->cam.plane);
        perp_dist = ray_cast(d);
		render_col(d, i, perp_dist);
    }
}
