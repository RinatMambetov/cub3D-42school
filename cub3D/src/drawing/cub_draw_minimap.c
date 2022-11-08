/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:10:23 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:10:28 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	cube_scale_img(t_cub3d *cub, int y, int x)
{
	int		x1;
	int		y1;
	int		scale;

	scale = cub->mlx_height / 3 / cub->map->width_f;
	x1 = (x + 1) * scale;
	y1 = (y + 1) * scale;
	x *= scale;
	y *= scale;
	while (y < y1)
	{
		while (x < x1)
		{
			cub->img.addr[y * cub->mlx_width + x] = 0xf0f000;
			x++;
		}
		x -= scale;
		y++;
	}
}

static void	cub_draw_map(t_cub3d *cub)
{
	int		x;
	int		y;

	y = 0;
	while (y < cub->map->height_f)
	{
		x = 0;
		while (x < cub->map->width_f)
		{
			if (cub->map->arr[y][x] == '1')
				cube_scale_img(cub, y, x);
			x++;
		}
		y++;
	}
}

static void	cub_draw_player(t_cub3d *cub, double x, double y)
{
	int	scale;
	int	x1;
	int	y1;

	scale = cub->mlx_height / 3 / cub->map->width_f;
	y *= scale;
	x *= scale;
	x1 = x - scale;
	y1 = y - scale;
	scale /= 2;
	while (y1 < y + scale)
	{
		while (x1 < x + scale)
		{
			if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) < scale * scale)
				cub->img.addr[y1 * cub->mlx_width + x1] = 0xff0000;
			x1++;
		}
		x1 = x - scale;
		y1++;
	}
}

void	cub_draw_minimap(t_cub3d *cub)
{
	cub_draw_map(cub);
	cub_draw_player(cub, cub->player->x, cub->player->y);
}
