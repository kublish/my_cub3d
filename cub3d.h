/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 02:02:04 by zkubli            #+#    #+#             */
/*   Updated: 2020/12/11 13:49:44 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MOVE_SPEED .05
# define TURN_SPEED .04908738521
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

typedef struct	s_img
{
	int			width;
	int			height;
	int			bpp;
	int			sl;
	int			endian;
	void		*ptr;
	void		*adr;
}				t_img;

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

typedef struct  s_ray_data
{
	t_dpoint	dir;
	t_point		hit;
	t_point		inc;
	t_dpoint	sideDist;
	t_dpoint	deltaDist;
    int         is_NS;
}               t_ray_data;

typedef struct	s_col
{
	int			wall_start;
	int			wall_end;
	int			wall_size;
	t_img		*tex;
	t_point		tcord;
}				t_col;

typedef struct	s_sprite
{
	double		dist;
	t_point		pos;
}				t_sprite;

typedef struct	s_data
{
	void 		*mlx_ptr;
	void		*win;
	t_img		no_tex;
	t_img		so_tex;
	t_img		ea_tex;
	t_img		we_tex;
	t_img		spr_tex;
	int			floor_color;
	int			ceil_color;
	t_point		res;
	t_cam		cam;
	t_ray_data	ray;
	char		*error_data;
	t_map		map;
	t_img		screen;
	t_vector	*sprites;
}				t_data;

void			launch(t_data *data);
void			render_screen(t_data *data);

int input(char *input, t_data *data);

//getters.c

int				gnl(int fd, char **line);
int				get_resolution(char *line, t_point *to_fill);
int				get_texture(char * line, t_data *data, t_img *tex);
int				get_color(char *line, int *color);

//movement.c

void			rotate_cam(double rad, t_data *d);
void			move_cam(int direction, t_data *d);

//render.c

void			render_screen(t_data *d);

//hooks.c
int				my_key_hook(int keycode, void *param);
int				my_press_hook(int keycode, void *param);
int				my_mouse_hook(int button, int x, int y, void *param);
int				my_expose_hook(void *param);
int				my_loop_hook(void *param);

//map_reader.c

int				read_map(char *line, int fd, t_data *data);

//tools.c

int				is_player(const char a);
void			ray_init(t_data *d, double ratio);
double			ray_cast(t_data *d);

//sprite.c

int				sprite_cmp(void *a, void *b);
#endif
