/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:27:24 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/15 14:41:41 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/cub3d.h"

void	draw_ceiling(t_img_info img, int ceiling)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			*(int *)(img.addr + (y * img.size_line + x * (img.bpp / 8))) = ceiling;
	}
}

void	draw_floor(t_img_info img, int floor)
{
	int		x;
	int		y;

	y = HEIGHT / 2 - 1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			*(int *)(img.addr + (y * img.size_line + x * (img.bpp / 8))) = floor;
	}
}
