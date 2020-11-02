/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 02:02:04 by zkubli            #+#    #+#             */
/*   Updated: 2020/11/01 13:42:30 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
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

typedef struct	s_texture
{
	int			width;
	int			height;
	void		*img;
}				t_texture;

typedef struct	s_map
{
	int			rowlen;
	int			tablelen;
	char		*table;
}				t_map;

typedef struct	s_cam
{
	t_dpoint	player;
	t_point		player_int;
	t_dpoint	dir;
	double		plane;	
}				t_cam;

typedef struct	s_data
{
	void 		*mlx_ptr;
	void		*win;
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	ea_tex;
	t_texture	we_tex;
	t_texture	spr_tex;
	int			floor_color;
	int			ceil_color;
	t_point		res;
	t_cam		cam;
	char		*error_data;
	t_map		map;
}				t_data;

typedef struct  s_ray_data
{
    t_double    rel_pos;
    int         is_NS;
}               t_ray_data;

void			launch(t_data *data);
void			render_screen(t_data *data);

int input(char *input, t_data *data);

//getters.c

int				gnl(int fd, char **line);
int				get_resolution(char *line, t_point *to_fill);
int				get_texture(char * line, t_data *data, t_texture *tex);
int				get_color(char *line, int *color);

//hooks.c
int my_key_hook(int keycode, void *param);
int my_mouse_hook(int button, int x, int y, void *param);
int my_expose_hook(void *param);
int my_loop_hook(void *param);

//map_reader.c

int				read_map(char *line, int fd, t_data *data);

//tools.c

int				is_player(const char a);
void            perp_vec(t_dpoint *vec, double ratio, t_dpoint re_vec);
int             ray_cast(t_dpoint *ray, t_data *d, t_dpoint *hit, int *is_NS);
)#endif
