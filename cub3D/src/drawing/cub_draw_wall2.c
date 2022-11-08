/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_wall2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:11:30 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:11:32 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	cub_draw_texture(t_cub3d *cub, \
		t_map *map, t_draw *draw)
{
	while (draw->y < draw->drawend)
	{
		draw->texy = (int)draw->texpos & (map->tex->width - 1);
		draw->texpos += draw->step;
		if (draw->side == 1 && draw->mapy < cub->player->y)
			draw->tn = 0;
		else if (draw->side == 1)
			draw->tn = 1;
		else if (draw->side == 0 && draw->mapx < cub->player->x)
			draw->tn = 2;
		else
			draw->tn = 3;
		cub->img.addr[draw->y * cub->mlx_width + draw->x] = \
			map->tex[draw->tn].data[draw->texy * map->tex->width + draw->texx];
		draw->y++;
	}
}

void	cub_draw_celing(t_cub3d *cub, t_draw *draw)
{
	while (draw->y < draw->drawstart)
	{
		cub->img.addr[draw->y * cub->mlx_width + draw->x] = cub->map->c_color;
		draw->y++;
	}
}

void	cub_draw_floor(t_cub3d *cub, t_draw *draw)
{
	while (draw->y < cub->mlx_height)
	{
		cub->img.addr[draw->y * cub->mlx_width + draw->x] = cub->map->f_color;
		draw->y++;
	}
}

void	cub_draw_wall2(t_cub3d *cub, t_draw *draw)
{
	draw->y = 0;
	cub_draw_celing(cub, draw);
	draw->texx = (int)(draw->wallx * cub->map->tex->height);
	if ((draw->side == 0 && draw->ray_x > 0)
		|| (draw->side == 1 && draw->ray_y < 0))
		draw->texx = cub->map->tex->width - draw->texx - 1;
	draw->step = 1 * (double)cub->map->tex->height / draw->lineheight;
	draw->texpos = (draw->drawstart
			- cub->mlx_height / 2 + draw->lineheight / 2) * draw->step;
	cub_draw_texture(cub, cub->map, draw);
	cub_draw_floor(cub, draw);
}
