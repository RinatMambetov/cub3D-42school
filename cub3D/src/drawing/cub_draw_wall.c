/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:11:12 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:11:15 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_find_step_and_sidedist(t_cub3d *cub, t_draw *draw)
{
	draw->ray_x = cos(draw->angle * PI / 180);
	draw->ray_y = sin(draw->angle * PI / 180);
	draw->deltadistx = fabs(1 / draw->ray_x);
	draw->deltadisty = fabs(1 / draw->ray_y);
	draw->mapy = (int)cub->player->y;
	draw->mapx = (int)cub->player->x;
	draw->stepx = 1;
	if (draw->ray_x > 0)
		draw->sidedistx = (draw->mapx + 1 - cub->player->x) * draw->deltadistx;
	else
	{
		draw->stepx = -1;
		draw->sidedistx = (cub->player->x - draw->mapx) * draw->deltadistx;
	}
	draw->stepy = -1;
	if (draw->ray_y > 0)
		draw->sidedisty = (cub->player->y - draw->mapy) * draw->deltadisty;
	else
	{
		draw->stepy = 1;
		draw->sidedisty = (draw->mapy + 1 - cub->player->y) * draw->deltadisty;
	}
}

void	draw_find_hit_wall_dda(t_map *map, t_draw *draw)
{
	draw->hit = 0;
	draw->side = 0;
	while (draw->hit == 0)
	{
		if (draw->sidedistx < draw->sidedisty)
		{
			draw->sidedistx += draw->deltadistx;
			draw->mapx += draw->stepx;
			draw->side = 0;
		}
		else
		{
			draw->sidedisty += draw->deltadisty;
			draw->mapy += draw->stepy;
			draw->side = 1;
		}
		if (map->arr[draw->mapy][draw->mapx] == '1')
			draw->hit = 1;
	}
}

void	draw_find_perpwalldist_wallx(t_cub3d *cub, t_draw *draw)
{
	if (draw->side == 0)
		draw->perpwalldist = (draw->sidedistx - draw->deltadistx)
			* cos((cub->player->angle - draw->angle) * PI / 180);
	else
		draw->perpwalldist = (draw->sidedisty - draw->deltadisty)
			* cos((cub->player->angle - draw->angle) * PI / 180);
	draw->lineheight = (int)(cub->mlx_height / draw->perpwalldist
			/ tan(cub->player->view / 2 * PI / 180));
	draw->drawstart = -draw->lineheight / 2 + cub->mlx_height / 2;
	if (draw->drawstart < 0)
		draw->drawstart = 0;
	draw->drawend = draw->lineheight / 2 + cub->mlx_height / 2;
	if (draw->drawend >= cub->mlx_height)
		draw->drawend = cub->mlx_height - 1;
	if (draw->side == 0)
		draw->wallx = \
			cub->player->y - (draw->sidedistx - draw->deltadistx) * draw->ray_y;
	else
		draw->wallx = \
			cub->player->x + (draw->sidedisty - draw->deltadisty) * draw->ray_x;
	draw->wallx -= floor(draw->wallx + 1e-8);
}

void	cub_draw_wall(t_cub3d *cub)
{
	t_draw	draw;

	draw.angle_start = cub->player->angle + cub->player->view / 2;
	draw.angle_end = cub->player->angle - cub->player->view / 2;
	draw.angle_step = cub->player->view / cub->mlx_width;
	draw.angle = draw.angle_start;
	draw.x = 0;
	while (draw.angle > draw.angle_end)
	{
		draw_find_step_and_sidedist(cub, &draw);
		draw_find_hit_wall_dda(cub->map, &draw);
		draw_find_perpwalldist_wallx(cub, &draw);
		cub_draw_wall2(cub, &draw);
		draw.angle -= draw.angle_step;
		draw.x++;
	}
}
