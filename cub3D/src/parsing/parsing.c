/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:13:19 by hregina           #+#    #+#             */
/*   Updated: 2022/06/25 08:39:37 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_map	*map_init(void)
{
	t_map	*map;
	int		i;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		cub_error("Error map: malloc t_map *map");
	map->height_f = 0;
	map->width_f = 0;
	map->f_color = -1;
	map->c_color = -1;
	i = 0;
	while (i < 4)
	{
		map->wall_texture_path[i] = NULL;
		i++;
	}
	map->player_x = -1;
	map->player_y = -1;
	map->player_dir = '\0';
	map->arr = NULL;
	return (map);
}

static void	map_array_init(t_map *map)
{
	map->arr = ft_dyn_arr_mal_char(map->height_f, map->width_f);
	if (map->arr == NULL)
		cub_error("Error map: malloc map->arr");
	map->tex = (t_tex *)malloc(sizeof(t_tex) * 4);
	if (!map->tex)
		cub_error("Error malloc: map->tex");
}

t_map	*parsing_map(char *map_file)
{
	t_map	*map;
	t_list	*head_map;

	map = map_init();
	head_map = parsing_read_map(map_file, map);
	if (!head_map)
		cub_error("Error map: malloc t_list *head_map");
	map_array_init(map);
	parsing_list_to_array(head_map, map);
	ft_lstclear(&head_map, free);
	parsing_check_map_surrounding(map);
	return (map);
}
