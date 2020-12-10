/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:58:56 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/04 20:52:12 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "cub3d.h"

void	init_col(t_data *d, t_col *c, double perp_dist)
{
	double	wallx;
	void	*re_val;	
	
	c->wall_start = (int)((d->res.y - d->res.y / perp_dist / 2) / 2);
	c->wall_end = (int)((d->res.y +  d->res.y / perp_dist / 2) / 2);
	c->wall_size = c->wall_end - c->wall_start;
	if (d->ray.is_NS)
		c->tex = (d->ray.hit.y + .5 < d->cam.player.y ?
				&d->no_tex : &d->so_tex);
	else
		c->tex = (d->ray.hit.x + .5 < d->cam.player.x ?
				&d->we_tex : &d->ea_tex);
	wallx = (d->ray.is_NS ? d->cam.player.x + d->ray.dir.x * perp_dist :
		       d->cam.player.y + d->ray.dir.y * perp_dist);	
	wallx -= floor(wallx);
	c->tcord.x = wallx * c->tex->width;	
	c->tcord.y = 0;
}

void	render_col(t_data *data, int x, double perp_dist)
{
	t_col	c;
	int		y;
	int		color;

	if (perp_dist < 0)
		return ;
	init_col(data, &c, perp_dist);
	y = 0;
	while (y < data->res.y)
	{
			if (y < c.wall_start)
				color = 0x00FFFFFF;	//ceiling color
			else if (y > c.wall_end)
				color = 0x00333333; //floor color
			else
			{
				c.tcord.y = (c.tex->height * (y - c.wall_start) / ((double)(c.wall_size)));
				color = ((int *)(c.tex->adr))[(c.tcord.x + c.tcord.y
						* c.tex->width)];
			}
			((int *)(data->screen.adr))[x + y++ * data->res.x] = color;
	}  
}

void	render_screen(t_data *d)
{
	int			i;
	double		perp_dist;
	//fprintf(stderr, "render start.\n");
	i = 0;
	while (i < d->res.x)
    {
        ray_init(d, ((i + 1.0) / d->res.x - .5) * d->cam.plane);
        perp_dist = ray_cast(d);
		render_col(d, i, perp_dist);
		i++;
    }
	mlx_put_image_to_window(d->mlx_ptr, d->win, d->screen.ptr, 0, 0);
	//fprintf(stderr, "render end.\n");
}
