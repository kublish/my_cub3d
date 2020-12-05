/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 01:29:10 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/04 20:53:48 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

int my_key_hook(int keycode, void *param)
{
	//fprintf(stderr, "keycode: %d\n", keycode);
	if (keycode == 65361)
		rotate_cam(TURN_SPEED, param);
	else if (keycode == 65363)
		rotate_cam(-TURN_SPEED, param);
	else if (keycode == 119)
		move_cam(0, param);
	else if (keycode == 100)
		move_cam(1, param);
	else if (keycode == 115)
		move_cam(2, param);
	else if (keycode == 97)
		move_cam(3, param);
	render_screen(param);
	return (0);
}

int	my_press_hook(int keycode, void *param)
{
	//fprintf(stderr, "test:%d\n", keycode);
	//fprintf(stderr, "param:%p", param);
}

int my_mouse_hook(int button, int x, int y, void *param)
{
	fprintf(stderr, "button: %d at %6d, %5d\n", button, x, y);
	return (0);
}

int my_expose_hook(void *param)
{
	fprintf(stderr, "YOU'VE BEEN EXPOSED");
	return (0);
}

int my_loop_hook(void *param)
{
	return (0);
}
