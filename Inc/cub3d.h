/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:08:52 by kyujlee           #+#    #+#             */
/*   Updated: 2022/05/30 18:44:08 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <mlx.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libft/libft.h"
#include "../Src/gnl/get_next_line.h"

#define height 1240
#define width 880
#define wall_width 64
#define wall_height 64

enum e_event_index
{
	K_A = 0,
	K_S = 1,
	K_D = 2,
	K_PRESS = 2,
	K_RELEASE = 3,
	K_W = 13,
	E_EXIT = 17,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT = 124,
};

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	l;
	bool	r;
}	t_key;

typedef struct s_coordinate_i
{
	int x;
	int y;
}	t_coordinate_i;

typedef struct s_coordinate_d
{
	double x;
	double y;
}	t_coordinate_d;

typedef struct s_player
{
	t_coordinate_d	pos;
	t_coordinate_d	dir;
	t_coordinate_d	plane;
	double			move_speed;
	double			rot_speed;
}	t_player;

typedef struct	s_img_info
{
	char	*addr;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img_info;

typedef struct s_map_info
{
	int		floor;
	int		ceiling;
	char	*path[4];
	t_img_info	img[4];
	char	**map;
	int		map_fd;
	t_list	*map_lst;
}	t_map_info;

typedef struct s_dda_calc
{
	double			camera_x;
	t_coordinate_d	ray_dir;
	t_coordinate_i	map;
	t_coordinate_d	side_dist;
	t_coordinate_d	delta_dist;
	double			per_dist;//perpenducular distance
	t_coordinate_i	step;
	int				hit;
	int				side;
}	t_dda_calc;

typedef struct s_dda_draw
{
	int line_height;
	int	draw_start;
	int	draw_end;
	int wall_index;
	double	wall_x;
	t_coordinate_i tex;
	double	step;
	double	tex_pos;
	int	color;
}	t_dda_draw;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_player		player;
	t_key			key_state;
	t_map_info		map;
	t_dda_calc		dda_calc;
	t_dda_draw		dda_draw;
}	t_game;


/*
** init_game.c --- initializing the struct 'game' except view
*/
void		init_key_state(t_key *key);
void    	init_player(t_player *player);
void		init_map_info(void *mlx_ptr, t_map_info *map, void *win_ptr);


/*
** draw_background.c --- draw background
*/
void		draw_ceiling(t_img_info img, int ceiling);
void		draw_floor(t_img_info img, int floor);

/*
** draw_wall.c --- draw wall / raycasting / MAIN LOGIC
*/
void		draw_wall(t_game *game, t_img_info *img);

/*
** draw_wall2.c --- draw wall / draw wall / MAIN LOGIC
*/
void		draw_line(int x, t_game *game, t_img_info *img);

/*
** moving.c --- change value when hook some events
*/
void    	moving(t_game *game);

/*
** utils.c --- utilities
*/
int			end_program(void);
t_img_info	load_img(void *mlx, int w, int h,
				char *path,void *win_ptr);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);

/*
** init.c --- related to init_info
*/

#endif