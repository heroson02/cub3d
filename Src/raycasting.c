/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:48 by kyujlee           #+#    #+#             */
/*   Updated: 2022/05/27 16:15:27 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

int main_loop(t_game *game)
{
    t_img_info img;

	moving(game);
    img.img_ptr = mlx_new_image(game->mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	draw_ceiling(img, game->map.ceiling);
	draw_floor(img, game->map.floor);
    draw_wall(game, &img);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx_ptr, img.img_ptr);
    return (0);
}

void init_game(t_game *game)
{
    init_player(&game->player);
	init_key_state(&game->key_state);
    game->mlx_ptr = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "cub3D");
    init_map_info(game->mlx_ptr, &game->map, game->win_ptr);
}

int main(int argc, char **argv)
{
    t_game game;

    init_game(&game);
    mlx_loop_hook (game.mlx_ptr, &main_loop, &game);
    mlx_hook(game.win_ptr, K_PRESS, 0, &key_press, &game);
    mlx_hook(game.win_ptr, K_RELEASE, 0, &key_release, &game);
    mlx_hook(game.win_ptr, E_EXIT, 0, end_program, &game);
    mlx_loop(game.mlx_ptr);
}