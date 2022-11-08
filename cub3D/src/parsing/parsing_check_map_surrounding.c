/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map_surrounding.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:13:34 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:13:35 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parsing_check_map_surrounding(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height_f)
	{
		x = 0;
		while (x < map->width_f)
		{
			if (map->arr[y][x] != '1' && map->arr[y][x] != ' ' && \
					(x == 0 || y == 0 || \
					x == map->width_f - 1 || y == map->height_f - 1 || \
					map->arr[y - 1][x] == ' ' || \
					map->arr[y + 1][x] == ' ' || \
					map->arr[y][x - 1] == ' ' || \
					map->arr[y][x + 1] == ' ' || \
					map->arr[y - 1][x - 1] == ' ' || \
					map->arr[y - 1][x + 1] == ' ' || \
					map->arr[y + 1][x - 1] == ' ' || \
					map->arr[y + 1][x + 1] == ' '))
				cub_error("Error map: the map is not surrounded by walls");
			x++;
		}
		y++;
	}
}
