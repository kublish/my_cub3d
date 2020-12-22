/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:06:47 by zacharyku         #+#    #+#             */
/*   Updated: 2020/11/25 00:11:41 by zacharyku        ###   ########.fr       */
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
		return (get_color(line + i + 1, &(data->floor_color), 0)); 
	else if (line[i] == 'C')
		return (get_color(line + i + 1, &(data->ceil_color), 1)); 
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
	return (!(d->no_tex.ptr && d->so_tex.ptr &&
			d->ea_tex.ptr && d->we_tex.ptr && d->spr_tex.ptr && d->floor_color
			&& d->ceil_color && d->res.x <= screenwidth &&
			d->res.x > 0 && d->res.y > 0
			));
}

int	get_input(int argc, char *v[], t_data *data, char **re_val)
{
	int len;

	if (argc >= 2)
	{
		if (((len = ft_strlen(v[1])) < 4) || v[1][len - 1] != 'b' ||
				v[1][len - 2] != 'u' || v[1][len - 3] != 'c' ||
				v[1][len - 4] != '.')
			return (21);
		if (!(argc >= 3 && ft_strcmp(v[2], "--save") == 0))	
				data->ss = 1;
		*re_val = v[1];
		return (0);
	}
	return (15);
}

int	input(int argc, char *argv[], t_data *data)
{
	int fd;
	int ecode;
	char *line;
	char *input;

	if((ecode = get_input(argc, argv, data, &input)))
		return (ecode);
	if ((fd = open(input, O_RDONLY, 666)) == -1)
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
