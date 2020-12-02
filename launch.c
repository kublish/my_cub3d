/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:54:13 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/02 15:52:37 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
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

void	launch(t_data *d)
{
	init_camera(d);	
	d->win = mlx_new_window(d->mlx_ptr, d->res.x, d->res.y, "zkubli cub3d");

	mlx_key_hook(d->win, &my_key_hook, (void *)d);
	mlx_mouse_hook(d->win, &my_mouse_hook, (void *)d);
	mlx_expose_hook(d->win, &my_expose_hook, (void *)d);
	mlx_loop_hook(d->win, &my_loop_hook, (void *)d);
	
	
	mlx_pixel_put(d->mlx_ptr, d->win, 10, 15, RED);	
	
	render_screen(d);	
	mlx_loop(d->mlx_ptr);
}
