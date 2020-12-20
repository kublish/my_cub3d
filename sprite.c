/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:54:33 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/11 13:49:15 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "cub3d.h"


void	find_sprites(t_data *d)
{
	int			i;
	t_sprite	*to_copy;

	d->sprites = ft_vnew(sizeof(t_sprite *));	
	i = 0;
	while (i < d->map.tablelen)
	{
		//fprintf(stderr, "tb[%4i]:\t%d\n", i, d->map.table[i]);	
		if (d->map.table[i] == '2')
		{	
			to_copy = malloc(sizeof(t_sprite));
			to_copy->dist = 0;
			to_copy->pos.x = i % d->map.rowlen;
			to_copy->pos.y = i / d->map.rowlen;
			ft_vadd(d->sprites, &to_copy);
			fprintf(stderr, "sprite found!\n");
			fprintf(stderr, "created sprite:%p\n", *((t_sprite **)(d->sprites->data)));
			fprintf(stderr, "x_check:%4d\n", (*(t_sprite **)(d->sprites->data))->pos.x);
			fprintf(stderr, "sprite_pos: %4d, %4d\n", to_copy->pos.x, to_copy->pos.y);
		}
		i++;
	}	
}

void	order_sprites(t_data *d)
{
	int i;
	double	a;
	double  b;
	double tmpposx;

	i = -1;
	while (++i < d->sprites->count)
	{
		a = d->cam.player.x - (*(t_sprite **)(ft_vget(d->sprites, i)))->pos.x;
		b = d->cam.player.y - (*(t_sprite **)(ft_vget(d->sprites, i)))->pos.y;
		(*((t_sprite **)(ft_vget(d->sprites, i))))->dist = a * a + b * b;
	}
	ft_vsort(d->sprites, &sprite_cmp);	
}

double	sprite_draw_init(t_data *d, t_sprite *s, t_point *dbeg, t_point *dend)
{
	t_dpoint	rel_pos;
	t_dpoint	transform;
	int		sprite_x;
	double		scale;
	
	rel_pos.x = s->pos.x - d->cam.player.x + .5;
	rel_pos.y = s->pos.y - d->cam.player.y + .5;
	transform.x = ((double)(d->cam.dir.x * rel_pos.y - d->cam.dir.y * rel_pos.x))
			/ d->cam.plane / d->res.x * d->res.y;	
	transform.y = ((double)(d->cam.dir.y * rel_pos.y + d->cam.dir.x * rel_pos.x));	
	sprite_x = (int)(d->res.x * (transform.x / transform.y + .5));	
	
	fprintf(stderr, "sprite_x: %d\n", sprite_x);
	scale = (d->res.y) / transform.y / d->cam.plane / 2;
	dbeg->x = (sprite_x - scale); //> 0 ? sprite_x - scale : 0);
	dend->x = (sprite_x + scale); //< d->res.x ? sprite_x + scale : d->res.x);
	dbeg->y = (d->res.y / 2 - scale) ;
	fprintf(stderr, "dbeg->y:%d\n", dbeg->y);
	dend->y = (d->res.y / 2 + scale);
	return (transform.y);
}

void	single_sprite(t_data *d, double depth, t_point *beg, t_point *end)
{
	t_point 	index;
	int		color;
	t_point		texpos;
	t_dpoint	denom;

	denom.x = (double)(end->x - beg->x) / d->spr_tex.width;
	denom.y = (double)(end->y - beg->y) / d->spr_tex.height;
	fprintf(stderr, "drawing sprite with width:%d\n", end->x - beg->x);
	fprintf(stderr, "drawing sprite with height:%d\n", end->y - beg->y);
	end->x = (end->x < d->res.x ? end->x : d->res.x);
	end->y = (end->y < d->res.y ? end->y : d->res.y);
	index.x = (beg->x > 0 ? beg->x : 0) - 1;
	while (++index.x < end->x)
	{
		if (depth >= *(double *)(ft_vget(d->depth_map, index.x)))
				continue ;
		texpos.x = (double)(index.x - beg->x) / denom.x;
		index.y = (beg->y > 0 ? beg->y : 0) - 1;
		while (++index.y < end->y)
		{
			texpos.y = (double)(index.y - beg->y) / denom.y;
	//		if (texpos.x > 63 || texpos.y > 63)
	//			fprintf(stderr, "texpos: %4d\t%4d\ndenom: %4lf\t%4lf\n", texpos.x, texpos.y, denom.x, denom.y);
			color = ((int *)(d->spr_tex.adr))[texpos.x + texpos.y * d->spr_tex.width];
			if (color & 0x00FFFFFF)
				((int *)(d->screen.adr))[index.x + index.y * d->res.x] = color;	
		}

	}
}

void	draw_sprites(t_data *d)
{
	double		depth;
	t_sprite	**s;
	t_point		drawstrt;	
	t_point		drawstop;

	order_sprites(d);
	s = (t_sprite **)(d->sprites->data);
	while ((size_t)(s) < (t_sprite **)(d->sprites->data) + d->sprites->count)
	{
		depth = sprite_draw_init(d, *s, &drawstrt, &drawstop);
		single_sprite(d, depth, &drawstrt, &drawstop);
		s++;
	}
}
