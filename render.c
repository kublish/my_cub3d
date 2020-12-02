/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:58:56 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/02 16:10:56 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "cub3d.h"

void render_col(t_data *data, int x, double perp_dist)
{
	int	wall_start;
	int	wall_end;
	int y;
	int color;

	//fprintf(stderr, "perp_d:%f\n", perp_dist);
	wall_start = (int)((data->res.y - data->res.y / perp_dist) / 2);
	wall_end = (int)ceil((data->res.y + data->res.y / perp_dist) / 2);
	y = 0;
	while (y < data->res.y)
	{
			if (y < wall_start)
				color = 0x00FFFFFF;	//ceiling color
			else if (y > wall_end)
				color = 0x00333333; //floor color
			else
				color = (data->ray.is_NS ? 0x00999999 : 0x00CCCCCC); //wallcolor
			mlx_pixel_put(data->mlx_ptr, data->win, x, y++, color);
	}  
}

void render_screen(t_data *d)
{
	int			i;
	double		perp_dist;
	fprintf(stderr, "render start.\n");
	i = 0;
	while (i < d->res.x)
    {
        ray_init(d, ((i + 1.0) / d->res.x - .5) * d->cam.plane);
        perp_dist = ray_cast(d);
		render_col(d, i, perp_dist);
		i++;
    }
	fprintf(stderr, "render end.\n");
}
