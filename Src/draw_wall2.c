/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:58:19 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/15 16:58:58 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

void	ft_pput(t_img_info *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int		ft_pget(t_img_info *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int*)dst);
}

void    init_wall_index(t_game *game, t_dda_draw *dd, t_dda_calc *dc)
{
    if (dc->side == 0)
    {
        dd->wall_x = game->player.pos.y + dc->per_dist * dc->ray_dir.y;
        dd->wall_index = 0;
    }
    else
    {
        dd->wall_x = game->player.pos.x + dc->per_dist * dc->ray_dir.x;
        dd->wall_index = 1;
    }
    dd->wall_x -= floor(dd->wall_x);
    dd->tex.x = (int)(dd->wall_x * (double)WALL_WIDTH);
    if (dc->side == 0 && dc->ray_dir.x > 0)
    {
        dd->tex.x = WALL_WIDTH - dd->tex.x - 1;
        dd->wall_index = 3;
    }
    if (dc->side == 1 && dc->ray_dir.y < 0)
    {
        dd->tex.x = WALL_WIDTH - dd->tex.x - 1;
        dd->wall_index = 2;
    }
}

void    init_dda_draw(t_game *game)
{
    t_dda_draw  *dd;

    dd = &game->dda_draw;
    dd->line_height = (int)(HEIGHT / game->dda_calc.per_dist);
    dd->draw_start = -(dd->line_height / 2) + (HEIGHT / 2);
    if (dd->draw_start < 0)
        dd->draw_start = 0;
    dd->draw_end = dd->line_height / 2 + HEIGHT / 2;
    if (dd->draw_end >= HEIGHT)
        dd->draw_end = HEIGHT - 1;
    init_wall_index(game, &game->dda_draw, &game->dda_calc);
    dd->step = 1.0 * WALL_HEIGHT / dd->line_height;
    dd->tex_pos = (dd->draw_start - HEIGHT / 2 + dd->line_height / 2) * dd->step;
}

void draw_line(int x, t_game *game, t_img_info *img)
{
    t_dda_draw  *dd;
    int         y;

    dd = &game->dda_draw;
    y = dd->draw_start - 1;
    init_dda_draw(game);
    while (++y < dd->draw_end)
    {
        dd->tex.y = (int)dd->tex_pos & (WALL_HEIGHT - 1);
        dd->tex_pos += dd->step;
        dd->color = ft_pget(&game->map.img[dd->wall_index], dd->tex.x, dd->tex.y);
        ft_pput(img, x, y, dd->color);
    }
}