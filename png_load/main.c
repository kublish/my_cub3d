/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:54:36 by zacharyku         #+#    #+#             */
/*   Updated: 2020/09/20 08:04:48 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "cub3d.h"

void	launch(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->window = mlx_new_window(data->mlx_ptr, 2000, 1000, "My Window");
	
	mlx_pixel_put(data->mlx_ptr, data->window, 10, 15, RED);	
	
	int width = 400;
	int height = 500;
	fprintf(stderr, "art");
	void *img;
	img = mlx_xpm_file_to_image(data->mlx_ptr, "gay.xpm", &width, &height);
	fprintf(stderr, "fart:%lld\n", img);
	mlx_put_image_to_window(data->mlx_ptr, data->window, img, 20, 20);
	fprintf(stderr, "party\n");		
	mlx_loop(data->mlx_ptr);
}

int main(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->width = 400;
	data->height = 300;
	launch(data);
}
