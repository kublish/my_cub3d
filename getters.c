/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:05:28 by zacharyku         #+#    #+#             */
/*   Updated: 2020/10/30 17:31:17 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
**	Super-simple "get next line" for one file at a time. Returns 1
**	when there is nothing more to deliver.
**  The bzero is a little over kill I only need to zero the first char and
**  the one after the read length, but it's written like this for line limits
*/

int	gnl(int fd, char **line)
{
	static char	buffer[READ_BUF + 1];
	char		*split;

	//fprintf(stderr, "buffer: %s\n", buffer);	
	*line = ft_strdup(buffer);
	ft_bzero(buffer, (READ_BUF + 1) *sizeof(char));
	while ((split = ft_strchr(*line, '\n')) == NULL)
		if(read(fd, buffer, READ_BUF) > 0)
			ft_strappend(line, buffer);
		else if (**line == '\0')
		{
			free(*line);
			return (1);
		}
		else
			return (0);
	ft_strcpy(buffer, split + 1);
	*(split) = '\0';
	return (0);
}

int get_resolution(char *line, t_point *to_fill)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		return (3);
	to_fill->x = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		return (3);
	to_fill->y = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	return (3 * (line[i] != '\0'));
}

int	get_texture(char *line, t_data *data, t_texture *tex)
{
	while (ft_isspace(*line))
		line++;
	if ((tex->img = mlx_xpm_file_to_image
			(data->mlx_ptr, line, &(tex->width), &(tex->height))))
		return (4 * (tex->width <= 0 || tex->height <= 0));
	if ((tex->img = mlx_png_file_to_image
			(data->mlx_ptr, line, &(tex->width), &(tex->height))))
		return (4 * (tex->width <= 0 || tex->height <= 0));
	data->error_data = ft_strdup(line);
	return (4);
}

int get_color(char *line, int *color)
{
	int i;
	int tmpcolor;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	*color = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	if (*color & ~0xFF || line[i++] != ',')
		return (1);
	*color <<= 16;
	tmpcolor = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	if (tmpcolor & ~0xFF || line[i++] != ',')
		return (1);
	*color += tmpcolor << 8;
	tmpcolor = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	if (tmpcolor & ~0xFF || (line[i] != ' ' && line[i] != '\0'))
		return (1);
	color += tmpcolor;
	return (0);
}
