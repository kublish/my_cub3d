/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 01:29:10 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/02 12:56:24 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

int my_key_hook(int keycode, void *param)
{
	fprintf(stderr, "keycode: %d\n", keycode);
	return (0);
}

int my_mouse_hook(int button, int x, int y, void *param)
{
	fprintf(stderr, "button: %d at %6d, %5d\n", button, x, y);
	rotate_cam(.1, param);
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
