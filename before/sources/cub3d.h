/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:53:06 by yson              #+#    #+#             */
/*   Updated: 2022/05/30 18:03:24 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int flag;
	//0~255인지 검사하기
}	t_rgb;

typedef struct s_image
{
	void	*no;
	void	*ea;
	void	*we;
	void	*so;
	
	//북동서남 순서로 index
}	t_image;

typedef struct s_info
{
	void	*mlx_ptr;
	t_rgb	floor;		//game->map->floor
	t_rgb	ceilling;   //game->map->ceilling
	t_image	image;		//game->map->img
	char 	**map;		//game->map->map

	int		map_fd;		//game->map
	t_list	*map_lst;	//game->map
}	t_info;

typedef enum e_type
{
	E_ERROR = 0,
	E_NO,
	E_SO,
	E_WE,
	E_EA,
	E_FLOOR,
	E_CEILLING,
	E_MAP
}	t_type;

// 
#include <mlx.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define height 640
#define width 480
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
	void	*img_ptr;
	char	*addr;
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

// 
int	ft_strcmp(char *s1, char *s2);
void	free_split(char **split);
void	err_exit(char *str);
int	ft_atoi_ad(const char *str);
#endif