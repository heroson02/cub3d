/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:23:49 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/15 18:08:47 by yson             ###   ########.fr       */
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
	(void)game;
    player->pos.x = 12;
	player->pos.y = 5;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->move_speed = 0.1;
	player->rot_speed = 0.1;
    // rotate_camera(game, camera_flag('E'));
}
