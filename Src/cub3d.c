/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:48 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/16 19:03:20 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

int	main_loop(t_game *game)
{
	t_img_info	screen;

	moving(game);
	screen.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	screen.addr = mlx_get_data_addr(screen.img_ptr, &screen.bpp,
			&screen.size_line, &screen.endian);
	draw_ceiling(screen, game->map.ceiling);
	draw_floor(screen, game->map.floor);
	draw_wall(game, &screen);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, screen.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx_ptr, screen.img_ptr);
	return (0);
}

void	init_game(t_game *game)
{
	init_player(&game->player);
	init_key_state(&game->key_state);
	game->mlx_ptr = mlx_init();
	read_map(game);
	check_map(game);
	convert_map(game, 0, 0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!arg_check(argc, argv, &game.map))
		err_exit("Wrong path");
	init_game(&game);
	mlx_loop_hook (game.mlx_ptr, &main_loop, &game);
	mlx_hook(game.win_ptr, K_PRESS, 0, &key_press, &game);
	mlx_hook(game.win_ptr, K_RELEASE, 0, &key_release, &game);
	mlx_hook(game.win_ptr, E_EXIT, 0, end_program, &game);
	mlx_loop(game.mlx_ptr);
}
