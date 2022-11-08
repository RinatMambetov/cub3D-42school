/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_list_to_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:13:53 by hregina           #+#    #+#             */
/*   Updated: 2022/06/24 20:50:20 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	parsing_arr_line(int y, char *line, t_map *map)
{
	int	x;

	x = 0;
	while (*line)
	{
		if (*line == '0' || *line == '1' || *line == ' ')
			map->arr[y][x] = *line;
		else if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
			map->arr[y][x] = '0';
		else
			cub_error("Error map: wrong symbol in map");
		line++;
		x++;
	}
	while (x < map->width_f)
	{
		map->arr[y][x] = ' ';
		x++;
	}
}

void	parsing_list_to_array(t_list *head, t_map *map)
{
	int	y;

	y = 0;
	while (head)
	{
		parsing_arr_line(y, head->content, map);
		head = head->next;
		y++;
	}
}
