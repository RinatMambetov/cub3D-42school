/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:12:10 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:12:13 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	player_rotate(t_cub3d	*cub, char key)
{
	if (cub->mouse != 0)
		cub->player->rotspeed *= 2;
	if (key == 123)
	{
		cub->player->angle += cub->player->rotspeed;
		if (cub->player->angle >= 360)
			cub->player->angle = 0;
		if (cub->player->angle <= -360)
			cub->player->angle = 0;
	}
	else if (key == 124)
	{
		cub->player->angle -= cub->player->rotspeed;
		if (cub->player->angle >= 360)
			cub->player->angle = 0;
		if (cub->player->angle <= -360)
			cub->player->angle = 0;
	}
	if (cub->mouse != 0)
		cub->player->rotspeed /= 2;
}

void	player_updown(t_cub3d *cub, double tmp_x, double tmp_y)
{
	if (cub->active_key[13] == 1)
	{
		if (cub->map->arr[(int)(cub->player->y)]
		[(int)(cub->player->x + tmp_x)] == '0')
			cub->player->x += tmp_x;
		if (cub->map->arr[(int)(cub->player->y + tmp_y)]
		[(int)(cub->player->x)] == '0')
			cub->player->y += tmp_y;
	}
	else if (cub->active_key[1] == 1)
	{
		if (cub->map->arr[(int)(cub->player->y)]
		[(int)(cub->player->x - tmp_x)] == '0')
			cub->player->x -= tmp_x;
		if (cub->map->arr[(int)(cub->player->y - tmp_y)]
		[(int)(cub->player->x)] == '0')
			cub->player->y -= tmp_y;
	}
}

void	player_leftright(t_cub3d *cub, double tmp_x, double tmp_y)
{
	if (cub->active_key[2] == 1)
	{
		if (cub->map->arr[(int)(cub->player->y)]
		[(int)(cub->player->x - tmp_y)] == '0'
			&& cub->map->arr[(int)(cub->player->y + tmp_x)]
			[(int)(cub->player->x)] == '0')
		{
			cub->player->x -= tmp_y;
			cub->player->y += tmp_x;
		}
	}
	else if (cub->active_key[0] == 1)
	{
		if (cub->map->arr[(int)(cub->player->y)]
		[(int)(cub->player->x + tmp_y)] == '0'
			&& cub->map->arr[(int)(cub->player->y - tmp_x)]
			[(int)(cub->player->x)] == '0')
		{
			cub->player->x += tmp_y;
			cub->player->y -= tmp_x;
		}
	}
}

void	update_move(t_cub3d	*cub)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = cub->player->movespeed * cos(cub->player->angle * PI / 180);
	tmp_y = -cub->player->movespeed * sin(cub->player->angle * PI / 180);
	if (cub->active_key[53] == 1)
		cub_close();
	else if (cub->active_key[123] == 1 || cub->mouse > 0)
		player_rotate(cub, 123);
	else if (cub->active_key[124] == 1 || cub->mouse < 0)
		player_rotate(cub, 124);
	player_updown(cub, tmp_x, tmp_y);
	player_leftright(cub, tmp_x / 2, tmp_y / 2);
}
