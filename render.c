/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:58:56 by zacharyku         #+#    #+#             */
/*   Updated: 2020/10/31 17:20:31 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"

void render_line(int x, t_data *data)
{
	int y;
	
	y = 0;
	while (y < data->res.y)
	{
			mlx_pixel_put(data->mlx_ptr, data->win, x, y++, x);
	}  
}

void render_screen(t_data *data)
{
	int i;

	i = 0;
	while (i < data->res.x)
		render_line(i++, data);
}
