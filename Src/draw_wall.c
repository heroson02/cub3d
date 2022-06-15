/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:29:18 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/15 16:07:16 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

int	worldMap[24][24] = {
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


void	init_side_dist(t_game *game)
{
	t_dda_calc *v;

	v = &game->dda_calc;
	if (v->ray_dir.x < 0)
	{
		v->step.x = -1;
		v->side_dist.x = (game->player.pos.x - v->map.x) * v->delta_dist.x;
	}
	else
	{
		v->step.x = 1;
		v->side_dist.x = (v->map.x + 1.0 - game->player.pos.x) * v->delta_dist.x;
	}
	if (v->ray_dir.y < 0)
	{
		v->step.y = -1;
		v->side_dist.y = (game->player.pos.y - v->map.y) * v->delta_dist.y;
	}
	else
	{
		v->step.y = 1;
		v->side_dist.y = (v->map.y + 1.0 - game->player.pos.y) * v->delta_dist.y;
	}
}

void	init_view(t_game *game, int x)
{
	t_dda_calc *v;

	v = &game->dda_calc;
	v->camera_x = (2 * x / (double)WIDTH) - 1;
	v->ray_dir.x = (game->player.dir.x + game->player.plane.x * v->camera_x);
	v->ray_dir.y = (game->player.dir.y + game->player.plane.y * v->camera_x);
	v->map.x = (int)game->player.pos.x;
	v->map.y = (int)game->player.pos.y;
	v->delta_dist.x = fabs(1 / v->ray_dir.x);
	v->delta_dist.y = fabs(1 / v->ray_dir.y);
	v->hit = 0;
	init_side_dist(game);
}

void    dda(t_game *game)
{
    t_dda_calc *v;

	v = &game->dda_calc;
    while (v->hit == 0)
    {
        if (v->side_dist.x < v->side_dist.y)
        {
            v->side_dist.x += v->delta_dist.x;
            v->map.x += v->step.x;
            v->side = 0;
        }
        else
        {
            v->side_dist.y += v->delta_dist.y;
            v->map.y += v->step.y;
            v->side = 1;
        }
        if (worldMap[v->map.x][v->map.y] > 0)
            v->hit = 1;
    }
    if (v->side == 0)
        v->per_dist = (v->map.x - game->player.pos.x + (1 - v->step.x) / 2)
                        / v->ray_dir.x;
    else
        v->per_dist = (v->map.y - game->player.pos.y + (1 - v->step.y) / 2)
                        / v->ray_dir.y;
}

void	draw_wall(t_game *game, t_img_info *img)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		init_view(game, x);
		dda(game);
		draw_line(x, game, img);
	}
}
