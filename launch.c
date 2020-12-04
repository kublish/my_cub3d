/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:54:13 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/03 18:55:46 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stdio.h>
#include <mlx.h>
#include "libft/libft.h"
#include "cub3d.h"
#include "hooks.h"

/*
void	set_hooks(t_d *d, void *param)
{
	mlx_key_hook(d->mlx_ptr, &my_loop_hook, param);
	mlx_mouse_hook(d->mlx_ptr, &my_loop_hook, param);
	mlx_expose_hook(d->mlx_ptr, &my_expose_hook, param);
	mlx_loop_hook(d->mlx_ptr, &my_loop_hook, param);
}
*/

void	init_camera(t_data *d)
{
	int i;

	i = 0;
	while (!is_player(d->map.table[i]))
		i++;
	d->cam.player_int.x = i % d->map.rowlen;
	d->cam.player_int.y = i / d->map.rowlen;
	d->cam.player.x = d->cam.player_int.x + .5;
	d->cam.player.y = d->cam.player_int.y + .5;
	if (d->map.table[i] == 'N' || d->map.table[i] == 'S')
	    d->cam.dir.y = (d->map.table[i] == 'N' ? -1 : 1);
	else
	    d->cam.dir.x = (d->map.table[i] == 'E' ? 1 : -1);
	d->cam.plane = 2.0;
}

void	init_screen(t_data *d)
{
	void *tmp;

	
	//d->screen.ptr = mlx_new_image(d->mlx_ptr, d->res.x, d->res.y);
	d->screen.ptr = mlx_new_image(d->mlx_ptr, d->res.x, d->res.y);
	d->screen.adr = mlx_get_data_addr(d->screen.ptr, &d->screen.bpp,
			&d->screen.sl, &d->screen.endian);
	fprintf(stderr, "bpp:%d\nsl%d\nendian:%d\n", d->screen.bpp, d->screen.sl,
			d->screen.endian);
}

void	launch(t_data *d)
{
	init_camera(d);	
	d->win = mlx_new_window(d->mlx_ptr, d->res.x, d->res.y, "zkubli cub3d");
	mlx_key_hook(d->win, &my_key_hook, (void *)d);
	mlx_hook(d->win, KeyPress, KeyPressMask, &my_press_hook, (void *)d);
	mlx_mouse_hook(d->win, &my_mouse_hook, (void *)d);
	mlx_expose_hook(d->win, &my_expose_hook, (void *)d);
	mlx_loop_hook(d->win, &my_loop_hook, (void *)d);
	
	init_screen(d);
	
	render_screen(d);	
	mlx_loop(d->mlx_ptr);
}
