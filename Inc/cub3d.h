/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:08:52 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/15 18:59:44 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../Src/gnl/get_next_line.h"

# define HEIGHT 1240
# define WIDTH 880
# define WALL_WIDTH 64
# define WALL_HEIGHT 64
# define NORTH_RADIANS 0
# define SOUTH_RADIANS 3.14159265358979323846
# define EAST_RADIANS  4.71238898038468967399
# define WEST_RADIANS  1.57079632679489661923 


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
	int	x;
	int	y;
}	t_coordinate_i;

typedef struct s_coordinate_d
{
	double	x;
	double	y;
}	t_coordinate_d;

typedef struct s_player
{
	t_coordinate_d	pos;
	t_coordinate_d	dir;
	t_coordinate_d	plane;
	double			move_speed;
	double			rot_speed;
}	t_player;

typedef struct s_img_info
{
	char	*addr;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img_info;

typedef struct s_map_info
{
	int		map_width;
	int		map_height;
	int		floor;
	int		ceiling;
	t_img_info	img[4];
	char	**map;
	int		**world_map;
	int		map_fd;
	t_list	*map_lst;
	int		ceiling_flag;
	int		floor_flag;
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
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				wall_index;
	double			wall_x;
	t_coordinate_i	tex;
	double			step;
	double			tex_pos;
	int				color;
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

typedef enum e_type
{
	E_ERROR = 0,
	E_NO,
	E_SO,
	E_WE,
	E_EA,
	E_FLOOR,
	E_CEILING,
	E_MAP
}	t_type;

/*
** init_game.c --- initializing the struct 'game' except view
*/
void	init_key_state(t_key *key);
void    init_player(t_game *game, t_player *player);
void	init_map_info(void *mlx_ptr, t_map_info *map, void *win_ptr);

/*
** draw_background.c --- draw background
*/
void	draw_ceiling(t_img_info img, int ceiling);
void	draw_floor(t_img_info img, int floor);

/*
** draw_wall.c --- draw wall / raycasting / MAIN LOGIC
*/
void	draw_wall(t_game *game, t_img_info *img);

/*
** draw_wall2.c --- draw wall / draw wall / MAIN LOGIC
*/
void	draw_line(int x, t_game *game, t_img_info *img);

/*
** moving.c --- change value when hook some events
*/
void	moving(t_game *game);

/*
** utils.c --- utilities
*/
int		end_program(void);
t_img_info	load_img(void *mlx, int w, int h,
			char *path, void *win_ptr);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);

/*
** utils_2.c --- utilities
*/

void	err_exit(char *str);
int	ft_strcmp(char *s1, char *s2);
void	free_split(char **split);
int	ft_atoi_ad(const char *str);
char	**lst_to_arr(t_game *game, t_list *head);

/*
** init.c --- related to init_info
*/
void	rotate_camera(t_game *game, double rot);
double	camera_flag(char c);

/*
** parsing.c --- parse .cub file and check validity
*/
void read_map(t_game *game);
int	arg_check(int argc, char **argv, t_map_info *info);

/*
** check_map.c --- check map
*/
void	check_map(t_game *game);

/*
** convert_map.c --- convert map
*/
void	convert_map(t_game *game);

//테스트용 함수
void split_print(t_game *game, char **split);
void split_print_int(t_game *game, int **split);
#endif
