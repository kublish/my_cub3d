/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:16:49 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/02 14:39:12 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	rotate_cam(double rad, t_data *d)
{
	double	x;
	double	y;	

	x = d->cam.dir.x;
	y = d->cam.dir.y;
    d->cam.dir.x = x * cos(rad) - y * sin(rad);
    d->cam.dir.y = x * sin(rad) + y * cos(rad);
}

/*
** directions: 0 = forward; 1 = right; 2 = backwards; 3 = left.
*/

void	move_cam(int direction, t_data *d)
{
	t_dpoint	to_move;
	double		swap_val;

	to_move.x = d->cam.dir.x * MOVE_SPEED;
	to_move.y = d->cam.dir.y * MOVE_SPEED;
	if (direction == 3 || direction == 2)
		to_move.x *= -1;
	if (direction == 2 || direction == 1)
		to_move.y *= -1;
	if (direction == 1 || direction == 3)
	{
		swap_val = to_move.x;
		to_move.x = to_move.y;
		to_move.y = swap_val;
	}		
	d->cam.player.x += to_move.x;
	d->cam.player.y += to_move.y;
}
