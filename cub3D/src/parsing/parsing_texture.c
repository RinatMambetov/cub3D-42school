/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:14:57 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:14:59 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parsing_check_texture_main(char *s)
{
	if (ft_strncmp("NO ", s, 3) == 0
		|| ft_strncmp("SO ", s, 3) == 0
		|| ft_strncmp("WE ", s, 3) == 0
		|| ft_strncmp("EA ", s, 3) == 0
		|| ft_strncmp("F ", s, 2) == 0
		|| ft_strncmp("C ", s, 2) == 0)
		return (1);
	else
		return (0);
}

int	parsing_texture(char *s, t_map *map)
{
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (parsing_check_texture_main(s))
		parsing_texture_main(ft_split(s, ' '), map);
	else
	{
		if (map->wall_texture_path[0]
			&& map->wall_texture_path[1]
			&& map->wall_texture_path[2]
			&& map->wall_texture_path[3]
			&& map->f_color != -1
			&& map->c_color != -1)
			return (0);
		else
			cub_error("Error map: miss texture path");
	}	
	return (1);
}
