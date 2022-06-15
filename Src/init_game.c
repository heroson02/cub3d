/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:23:49 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/15 17:02:57 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

void	init_key_state(t_key *key)
{
	key->w = false;
    key->a = false;
    key->s = false;
    key->d = false;
    key->l = false;
    key->r = false;
}

void	rotate_camera(t_game *game, double rot)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(rot) - game->player.dir.y * sin(rot);
	game->player.dir.y = old_dir_x * sin(rot) + game->player.dir.y * cos(rot);
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(rot) - game->player.plane.y * sin(rot);
	game->player.plane.y = old_plane_x * sin(rot) + game->player.plane.y * cos(rot);
}

double	camera_flag(char c)
{
	if (c == 'N')
		return (NORTH_RADIANS);
	if (c == 'S')
		return (SOUTH_RADIANS);
	if (c == 'W')
		return (WEST_RADIANS);
	if (c == 'E')
		return (EAST_RADIANS);
	return (0);
}

void    init_player(t_game *game, t_player *player)
{
    player->pos.x = 12;
	player->pos.y = 5;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->move_speed = 0.1;
	player->rot_speed = 0.1;
    rotate_camera(game, camera_flag('E'));
}

void init_map_info(void *mlx_ptr, t_map_info *map, void *win_ptr)
{   
    int rgb[2][3] = { {110,153,15}, {255,255,255} };

    map->ceiling = rgb[0][0] << 16 | rgb[0][1] << 8 | rgb[0][2];
    map->floor = rgb[1][0] << 16 | rgb[1][1] << 8 | rgb[1][2];

    map->path[0] = "./asset/north.xpm";
    map->path[1] = "./asset/east.xpm";
    map->path[2] = "./asset/west.xpm";
    map->path[3] = "./asset/south.xpm";
    
    map->img[0] = load_img(mlx_ptr, WALL_WIDTH, WALL_HEIGHT, map->path[0],win_ptr);
    map->img[1] = load_img(mlx_ptr, WALL_WIDTH, WALL_HEIGHT, map->path[1],win_ptr);
    map->img[2] = load_img(mlx_ptr, WALL_WIDTH, WALL_HEIGHT, map->path[2],win_ptr);
    map->img[3] = load_img(mlx_ptr, WALL_WIDTH, WALL_HEIGHT, map->path[3],win_ptr);
}
