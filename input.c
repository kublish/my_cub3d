/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:06:47 by zacharyku         #+#    #+#             */
/*   Updated: 2020/10/31 17:13:50 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "cub3d.h"
#include "libft/libft.h"



/*
**	Sorts through element data. Returns 0 on successful read. >0 on bad read.
**  -1 on non valid type identifier
**	I have no idea if a line containing spaces is an "empty line" so I'm
**	guessing it is. If it isn't just change line[i] to *line on the return
*/

int	get_element(char *line, t_data *data)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 'R')
		return (get_resolution(line + i + 1, &(data->res)));
	else if (line[i] == 'N' && line[i + 1] == 'O') 
		return (get_texture(line + i + 2, data, &(data->no_tex)));
	else if (line[i] == 'S' && line[i + 1] == 'O') 
		return (get_texture(line + i + 2, data, &(data->so_tex)));
	else if (line[i] == 'E' && line[i + 1] == 'A') 
		return (get_texture(line + i + 2, data, &(data->ea_tex)));
	else if (line[i] == 'W' && line[i + 1] == 'E') 
		return (get_texture(line + i + 2, data, &(data->we_tex)));
	else if (line[i] == 'S')
		return (get_texture(line + i + 2, data, &(data->spr_tex)));
	else if (line[i] == 'F')
		return (5 * !!(get_color(line + i + 1, &(data->floor_color)))); 
	else if (line[i] == 'C')
		return (6 * !!(get_color(line + i + 1, &(data->ceil_color)))); 
	else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i]
			== 'W' || line[i] == ' ' || line[i] == '1' || line[i] == '0')
		return (-1);
	return (7 * (line[i] != '\0'));
}

int	validate(t_data *d)
{
	int screenwidth;
	int	screenheight;

	if (!d || !(d->mlx_ptr))
		return (9);
	mlx_get_screen_size(d->mlx_ptr, &screenwidth, &screenheight);
	if (d->res.x > screenwidth)
		d->res.x = screenwidth;
	if (d->res.y > screenheight)
		d->res.y = screenheight;
	return (!(d->no_tex.img && d->so_tex.img &&
			d->ea_tex.img && d->we_tex.img && d->spr_tex.img && d->floor_color
			&& d->ceil_color && d->res.x <= screenwidth &&
			d->res.x > 0 && d->res.y > 0
			));
}

int	input(char *input, t_data *data)
{
	int fd;
	int ecode;
	char *line;

	if ((fd = open(input, O_RDONLY)) == -1)
		return (8);
	while (gnl(fd, &line) != 1)
	{
		if ((ecode = get_element(line, data)))
			break;
		free(line);
	}
	if (ecode >= 0 || (ecode = validate(data)))
	{
		free(line);
		close(fd);
		return ((ecode == 0) ? 14 : ecode);
	}
	if ((ecode = read_map(line, fd, data)))
		return (ecode);
	close(fd);
	return (0);
}
