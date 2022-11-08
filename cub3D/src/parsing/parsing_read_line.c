/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:14:21 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:14:24 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	parsing_player(t_map *map, int i, char player_dir)
{
	if (map->player_dir != '\0')
		cub_error("Error map: more then one player");
	map->player_x = i;
	map->player_y = map->height_f;
	map->player_dir = player_dir;
}

static int	parsing_check_map(char *s, t_map *map)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if ((s[i] >= '0' && s[i] <= '1') || s[i] == ' ')
			;
		else if (s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E')
			parsing_player(map, i, s[i]);
		else
			return (0);
		i++;
	}
	if (map->width_f < i)
		map->width_f = i;
	map->height_f++;
	return (1);
}

void	parsing_read_line(int rd, char *line, t_map *map, t_list **head_map)
{
	t_list	*tmp;

	if (!line)
		cub_error("Error map: malloc error newline");
	if (!(map->height_f) && (!ft_strlen(line) || parsing_texture(line, map)))
	{
		free(line);
		return ;
	}
	if (!ft_strlen(line) && rd)
		cub_error("Error map: parsing - empty line in map");
	if (!ft_strlen(line) && !rd)
	{
		free (line);
		return ;
	}
	if (parsing_check_map(line, map))
	{
		tmp = ft_lstnew(line);
		if (!tmp)
			cub_error("Error map: cannot creat new list");
		ft_lstadd_back(head_map, tmp);
	}
	else
		cub_error("Error map: wrong symbol in map");
}
