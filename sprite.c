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

#include "libft/libft.h"
#include "cub3d.h"


int		sprite_cmp(void *a, void *b)
{
	return ((t_sprite)(a).dist > (t_sprite)(b).dist);
}

void	find_sprites(t_data *d)
{
	int			i;
	t_sprite	*to_copy;

	d->sprites = ft_vnew(sizeof(t_sprite *));	
	i = 0;
	while (i < d.map.tablelen)
	{
		if (d.map.table[i] == 2)
		{	
			to_copy = malloc(sizof(t_sprite));
			to_copy->dist = 0;
			to_copy->pos.x = i % d.map.rowlen;
			to_copy->pos.y = i / d.map.rowlen;
			ft_vadd(d->sprites, &to_copy);
		}
		i++;
	}
}

void	order_sprites(t_data *d)
{
	int i;
	int	a;
	int b;

	i = 0;
	while (i < d->sprites.count)
	{
		a = d->cam.player.x - (t_sprite *)(ft_vget(d->sprites, i))->pos.x;
		b = d->cam.player.y - (t_sprite *)(ft_vget(d->sprites, i))->pos.y;
		(t_sprite *)(ft_vget(d->sprites, i))->dist = a * a + b * b;
	}
	ft_vsort(d->sprites, &sprite_cmp);	
}

void	sprite_draw_init(t_data *d, t_sprite *s, t_dpoint *dpos, t_dpoint *dsiz)
{
	t_dpoint	transform;

	transform.x = (d->cam.dir.x * s->pos.y - d->cam.dir.y * s->pos.x)
			/ d->cam.plane;	
	transform.y = (d->cam.dir.y * s->pos.x - d->cam.dir.x * s->pos.y)
			/ d->cam.plane;	
	fprintf(stderr, "Some sprite: %4.2d, %4.2d\n", transform.x, transform.y);
}

void	draw_sprites(t_data *d)
{
	double		depth;
	t_sprite	*s;
	t_dpoint	drawpos;	
	t_dpoint	drawsize;

	order_sprites(d);
	s = (t_sprite *)(f_vget(d->sprites, 0));
	while (s < d->sprites.data +  d->sprites.count * d->sprites.elem_size)
	{
		drawpos.x = s->pos.x - d->cam.player.x; 
		drawpos.y = s->pos.y - d->cam.player.y; 
		depth = sprite_draw_init(d, s, drawpos, drawsize);
		s += d->sprites.elem_size;
	}
}
