/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:24:18 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/16 19:32:00 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

int	end_program(void)
{
	exit(0);
	return (0);
}

t_img_info	load_img(void *mlx, char *path, void *win_ptr)
{
	t_img_info	img;
	void		*temp;
	int			w;
	int			h;

	w = WALL_WIDTH;
	h = WALL_HEIGHT;
	(void)win_ptr;
	temp = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!temp)
		err_exit("Wrong file");
	img.img_ptr = temp;
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp,
			&img.size_line, &img.endian);
	return (img);
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
