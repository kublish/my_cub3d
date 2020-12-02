/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:16:49 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/02 12:59:54 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void rotate_cam(double rad, t_data *d)
{
	double	x;
	double	y;	

	x = d->cam.dir.x;
	y = d->cam.dir.y;
    d->cam.dir.x = x * cos(rad) - y * sin(rad);
    d->cam.dir.y = x * sin(rad) + y * cos(rad);
}
