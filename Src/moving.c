/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:30:28 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/15 16:18:57 by kyujlee          ###   ########.fr       */
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
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
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
    if (worldMap2[(int)dest.x][(int)dest.y] != 1)
    {
        game->player.pos.x = dest.x;
        game->player.pos.y = dest.y;
    }
}