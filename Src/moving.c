/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:30:28 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/16 18:16:21 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

int	worldMap2[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
							{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
							{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
							{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
							{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

void    move_wasd(t_coordinate_d *dest, t_game *game)
{
    t_player *player;

    player = &game->player;
    if (game->key_state.w == true)
    {
        dest->x += player->dir.x * player->move_speed;
        dest->y += player->dir.y * player->move_speed;
    }
    if (game->key_state.s == true)
    {
        dest->x -= player->dir.x * player->move_speed;
        dest->y -= player->dir.y * player->move_speed;
    }
    if (game->key_state.a == true)
    {
        dest->x -= player->plane.x * player->move_speed;
        dest->y -= player->plane.y * player->move_speed;
    }
    if (game->key_state.d == true)
    {
        dest->x += player->plane.x * player->move_speed;
        dest->y += player->plane.y * player->move_speed;
    }
}

void    rotate(t_game *game, double rot_speed)
{
    double  tmp;

    tmp = game->player.dir.x;
    game->player.dir.x = game->player.dir.x * cos(rot_speed) -
                            game->player.dir.y * sin(rot_speed);
    game->player.dir.y = game->player.dir.y * cos(rot_speed) +
                            tmp * sin(rot_speed);
    tmp = game->player.plane.x;
    game->player.plane.x = game->player.plane.x * cos(rot_speed) -
                            game->player.plane.y * sin(rot_speed);
    game->player.plane.y = game->player.plane.y * cos(rot_speed) +
                            tmp * sin(rot_speed);
}

void    rotate_lr(t_game *game)
{
    if (game->key_state.l == true)
        rotate(game, game->player.rot_speed);
    if (game->key_state.r == true)
        rotate(game, -(game->player.rot_speed));
}

void    moving(t_game *game)
{
    t_coordinate_d  dest;

    dest.x = game->player.pos.x;
    dest.y = game->player.pos.y;
    move_wasd(&dest, game);
    rotate_lr(game);
    if (game->map.world_map[(int)(dest.x)][(int)(game->player.pos.y)] != 1)
        game->player.pos.x = dest.x;
    if (game->map.world_map[(int)(game->player.pos.x)][(int)(dest.y)] != 1)
        game->player.pos.y = dest.y;
}
