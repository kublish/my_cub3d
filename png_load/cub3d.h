/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 02:02:04 by zkubli            #+#    #+#             */
/*   Updated: 2020/09/17 13:19:52 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# include <mlx.h>
# define CUB3D_H
# define READ_BUF	64
# define RED 		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_dpoint
{
	double		x;
	double		y;
}				t_dpoint;

typedef struct	s_data
{
	void 		*mlx_ptr;
	void		*window;
	int			width;
	int			height;
	char		*no_tex;
	char		*so_tex;
	char		*ea_tex;
	char		*we_tex;
	char		*spr_tex;
	int			floor_color;
	int			ceil_color;
	t_dpoint	player_pos;
	t_dpoint	camera_vec;
	t_dpoint	fov_vec;	
	t_point		player;
}				t_data;

void			launch(t_data *data);
void			render_screen(t_data *data);

int				gnl(int fd, char **line);
t_point			*get_resolution(char *line, t_data *data);
void			*get_texture(char * line, t_data *data);

#endif
