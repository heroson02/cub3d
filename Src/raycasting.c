/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:48 by kyujlee           #+#    #+#             */
/*   Updated: 2022/05/25 16:14:35 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

int	end_program(void)
{
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->key_state.w = true;
	else if (keycode == K_S)
		game->key_state.s = true;
	else if (keycode == K_A)
		game->key_state.a = true;
	else if (keycode == K_D)
		game->key_state.d = true;
	else if (keycode == K_LEFT)
		game->key_state.l = true;
	else if (keycode == K_RIGHT)
		game->key_state.r = true;
    else if (keycode == K_ESC)
        end_program();
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->key_state.w = false;
	else if (keycode == K_S)
		game->key_state.s = false;
	else if (keycode == K_A)
		game->key_state.a = false;
	else if (keycode == K_D)
		game->key_state.d = false;
	else if (keycode == K_LEFT)
		game->key_state.l = false;
	else if (keycode == K_RIGHT)
		game->key_state.r = false;
	return (0);
}

void	ft_pput(t_img_info *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}


static void	draw_ceiling(t_img_info img, int ceiling)
{
	int		x;
	int		y;

	y = -1;
	while (++y < height / 2)
	{
		x = -1;
		while (++x < width)
			ft_pput(&img, x, y, ceiling);
	}
}

static void	draw_floor(t_img_info img, int floor)
{
	int		x;
	int		y;

	y = height / 2 - 1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			ft_pput(&img, x, y, floor);
	}
}

int main_loop(t_game *game)
{
    t_img_info img;

    img.img_ptr = mlx_new_image(game->mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	draw_ceiling(img, game->map.ceiling);
	draw_floor(img, game->map.floor);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img.img_ptr, 0, 0);
    return (0);
}


void	init_key_state(t_key *key)
{
	key->w = false;
    key->a = false;
    key->s = false;
    key->d = false;
    key->l = false;
    key->r = false;
}

void    init_player(t_player *player)
{
    player->pos.x = 12;
	player->pos.y = 5;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->move_speed = 0.1;
	player->rot_speed = 0.1;
}

t_img_info	load_img(void *mlx, int w, int h, char *path,void *win_ptr)
{
	t_img_info	img;

	img.img_ptr = mlx_xpm_file_to_image(mlx, path, &w, &h);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	return (img);
}


void init_map_info(void *mlx_ptr, t_map_info *map, void *win_ptr)
{
    int		img_width=64;
	int		img_height=64;
    
    int rgb[2][3] = { {110,153,15}, {255,255,255} };

    map->ceiling = rgb[0][0] << 16 | rgb[0][1] << 8 | rgb[0][2];
    map->floor = rgb[1][0] << 16 | rgb[1][1] << 8 | rgb[1][2];

    map->path[0] = "./asset/north.xpm";
    map->path[1] = "./asset/east.xpm";
    map->path[2] = "./asset/west.xpm";
    map->path[3] = "./asset/south.xpm";
    
    map->img[0] = load_img(mlx_ptr, 64, 64, map->path[0],win_ptr);
    map->img[1] = load_img(mlx_ptr, 64, 64, map->path[1],win_ptr);
    map->img[2] = load_img(mlx_ptr, 64, 64, map->path[2],win_ptr);
    map->img[3] = load_img(mlx_ptr, 64, 64, map->path[3],win_ptr);
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