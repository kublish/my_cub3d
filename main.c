/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:54:36 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/03 17:17:13 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "cub3d.h"

static char error_codes[20][40] =
{
	"Unkown Error",
	"System Error: ",
	"Invalid Resolution",
	"Could not load texture: ",
	"Floor color invalid",
	"Ceiling color invalid",
	"Invalid charactor in scene description",
	"Could not open scene description file",
	"Incomplete data from description file",
	"Invalid charactor in map",
	/*
	**	10
	*/
	"No starting point on map",
	"More than one starting point in map",
	"Map is not enclosed",
	"Map not found"
};

void my_error(int ecode, t_data *data)
{
	ft_putstr("Error\n");
	ft_putstr(error_codes[ecode - 1]);
	if (data->error_data)
	{
		ft_putstr(data->error_data);
	}
	ft_putstr("\n");
}

void clear_data(t_data *d)
{
	if (d->no_tex.ptr)
		mlx_destroy_image(d->mlx_ptr, d->no_tex.ptr);
	if (d->so_tex.ptr)
		mlx_destroy_image(d->mlx_ptr, d->so_tex.ptr);
	if (d->ea_tex.ptr)
		mlx_destroy_image(d->mlx_ptr, d->ea_tex.ptr);
	if (d->we_tex.ptr)
		mlx_destroy_image(d->mlx_ptr, d->we_tex.ptr);
	if (d->spr_tex.ptr)
		mlx_destroy_image(d->mlx_ptr, d->spr_tex.ptr);
	if (d->win)
		mlx_destroy_window(d->mlx_ptr, d->win);
	free(d->error_data);
	free(d->map.table);
	mlx_destroy_display(d->mlx_ptr);
	free(d->mlx_ptr);
	system("leaks cub3d");
}

#include <stdio.h>

int main(void)
{
	t_data	*data;
	int		ecode;
	int		a, b;

	fprintf(stderr, "sizeof t_data:%lu\n", sizeof(t_data));
	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));
	data->mlx_ptr = mlx_init();
	if ((ecode = input("maps/sqr.cub", data)))
		my_error(ecode, data);
	else
	{
		launch(data);	
	}
	clear_data(data);
	free(data);
}
