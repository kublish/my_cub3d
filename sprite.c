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


int		sprite_cmp(void *a, void *b)
{
	return (((t_sprite *)(a))->dist > ((t_sprite *)(b))->dist);
}

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
			fprintf(stderr, "sprite:%p\n", ((t_sprite *)(d->sprites->data)));
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
		fprintf(stderr, "Ordeing sprite\n");
		fprintf(stderr, "sprite:%p\n", ((t_sprite *)(d->sprites->data)));
		fprintf(stderr, "i:%d\n", i);
		fprintf(stderr, "f_vget:%p\n", *((t_sprite **)(ft_vget(d->sprites, i))));

		fprintf(stderr, "sprites xpos%d\n", (*(t_sprite **)(ft_vget(d->sprites, i)))->pos.x);
		a = d->cam.player.x - (*(t_sprite **)(ft_vget(d->sprites, i)))->pos.x;
		fprintf(stderr, "f_vget:%p\n", *((t_sprite **)(ft_vget(d->sprites, i))));
		b = d->cam.player.y - (*(t_sprite **)(ft_vget(d->sprites, i)))->pos.y;
		fprintf(stderr, "f_vget:%p\n", *((t_sprite **)(ft_vget(d->sprites, i))));
		(*((t_sprite **)(ft_vget(d->sprites, i))))->dist = a * a + b * b;
		fprintf(stderr, "f_vget:%p\n", *((t_sprite **)(ft_vget(d->sprites, i))));
	}
	fprintf(stderr, "f_vget:%p\n", *((t_sprite **)(ft_vget(d->sprites, 0))));
	ft_vsort(d->sprites, &sprite_cmp);	
	fprintf(stderr, "f_vget:%p\n", *((t_sprite **)(ft_vget(d->sprites, 0))));
}

double	sprite_draw_init(t_data *d, t_sprite *s, t_dpoint *dpos, t_dpoint *dsiz)
{
	t_dpoint	transform;

	transform.x = (d->cam.dir.x * s->pos.y - d->cam.dir.y * s->pos.x)
			/ d->cam.plane;	
	transform.y = (d->cam.dir.y * s->pos.x - d->cam.dir.x * s->pos.y)
			/ d->cam.plane;	
	fprintf(stderr, "Some sprite: %4.2d, %4.2d\n", transform.x, transform.y);
	
	return (1.0);
}

void	draw_sprites(t_data *d)
{
	double		depth;
	t_sprite	*s;
	t_dpoint	drawpos;	
	t_dpoint	drawsize;

	order_sprites(d);
	s = *(t_sprite **)(ft_vget(d->sprites, 0));
	while (s < d->sprites->data + d->sprites->count * d->sprites->elem_size)
	{
		drawpos.x = s->pos.x - d->cam.player.x; 
		drawpos.y = s->pos.y - d->cam.player.y; 
		depth = sprite_draw_init(d, s, &drawpos, &drawsize);
		s += d->sprites->elem_size;
	}
}
