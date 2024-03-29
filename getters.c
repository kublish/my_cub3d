/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:05:28 by zacharyku         #+#    #+#             */
/*   Updated: 2020/11/30 14:20:38 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d.h"
#include <mlx.h>
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
	fprintf(stderr, "gnl:%s\n", *line);
	return (0);
}

int get_resolution(char *line, t_point *to_fill)
{
	int		i;

	if (to_fill->x != 0 || to_fill->y != 0)
		return (17);
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
	if (line[i] != '\0')
		return (3);
	return (16 * !!(to_fill->x <= 0 || to_fill->y <= 0));
}

int	get_texture(char *line, t_data *data, t_img *img)
{
	if (img->ptr)
	{
		data->error_data = ft_strdup(line);
		return (18);
	}
	while (ft_isspace(*line))
		line++;
	if ((img->ptr = mlx_xpm_file_to_image
			(data->mlx_ptr, line, &(img->width), &(img->height))))
	{
		img->adr = mlx_get_data_addr(img->ptr, &img->bpp, &img->sl, &img->endian);
		fprintf(stderr, "img->adr:%p\n", img->adr);
		if (!(img->adr))
			fprintf(stderr, "what the heck!\n");
		return (4 * (img->width <= 0 || img->height <= 0));
	}
	data->error_data = ft_strdup(line);
	return (4);
}

int get_color(char *line, int *color, int is_ceil)
{
	int i;
	int tmpcolor;

	if (*color != 0)
		return (19 + is_ceil);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	*color = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	if (*color & ~0xFF || line[i++] != ',')
		return (5 + is_ceil);
	*color <<= 16;
	tmpcolor = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	if (tmpcolor & ~0xFF || line[i++] != ',')
		return (5 + is_ceil);
	*color += tmpcolor << 8;
	tmpcolor = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	color += tmpcolor;
	return (!!(tmpcolor & ~0xFF || (line[i] != ' ' && line[i] != '\0')) * (5 + is_ceil));
}
