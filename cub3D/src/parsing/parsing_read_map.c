/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:14:40 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:14:42 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	open_file(char *file)
{
	int	len;
	int	fd;

	len = ft_strlen(file);
	if (ft_strcmp(file + len - 4, ".cub"))
		cub_error("Error map: file-map name incorrect");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		cub_error("Error map: cannot open file-map");
	return (fd);
}

t_list	*parsing_read_map(char *map_file, t_map *map)
{
	t_list	*head_map;
	char	*line;
	int		rd;
	int		fd;

	head_map = NULL;
	line = NULL;
	rd = 1;
	fd = open_file(map_file);
	while (rd)
	{
		rd = get_next_line(fd, &line);
		if (rd < 0)
			cub_error("Error map: cannot read file map");
		if (rd == 0 && !line)
			break ;
		parsing_read_line(rd, line, map, &head_map);
	}
	if (map->player_dir == '\0')
		cub_error("Error map: no player");
	if (map->height_f < 3 || map->width_f < 3)
		cub_error("Error map: too small");
	if (close(fd) < 0)
		cub_error("Error map: cannot close file map");
	return (head_map);
}
