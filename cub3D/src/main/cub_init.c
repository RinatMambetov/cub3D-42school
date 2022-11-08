/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:07:18 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:07:22 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_texture(t_cub3d *cub, t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map->tex[i].ptr = \
			mlx_xpm_file_to_image(cub->mlx, map->wall_texture_path[i], \
			&map->tex[i].width, &map->tex[i].height);
		if (!map->tex[i].ptr)
			cub_error("Error cub->map->tex[i].ptr");
		map->tex[i].data = (int *)mlx_get_data_addr(map->tex[i].ptr, \
			&map->tex[i].bpp, &map->tex[i].size_l, &map->tex[i].endian);
		if (!map->tex[i].data)
			cub_error("Error cub->map->tex[i].data");
		i++;
	}
}

static t_player	*player_init(t_map *map)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		cub_error("Error malloc: t_player *player");
	player->x = map->player_x + 0.5;
	player->y = map->player_y + 0.5;
	if (map->player_dir == 'N')
		player->angle = 90;
	else if (map->player_dir == 'S')
		player->angle = 270;
	else if (map->player_dir == 'W')
		player->angle = 180;
	else if (map->player_dir == 'E')
		player->angle = 0;
	player->view = 60;
	player->movespeed = 0.1;
	player->rotspeed = 1.5;
	return (player);
}

t_cub3d	*cub_init(char *map_file)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (!cub)
		cub_error("Error malloc: t_cub3d *cub");
	cub->map = parsing_map(map_file);
	cub->mlx_width = 1280;
	cub->mlx_height = 720;
	cub->mouse = 0;
	cub->player = player_init(cub->map);
	cub->mlx = mlx_init(cub->map);
	init_texture(cub, cub->map);
	cub->mlx_win = mlx_new_window(cub->mlx, \
		cub->mlx_width, cub->mlx_height, "cub3D");
	cub->img.img = mlx_new_image(cub->mlx, cub->mlx_width, cub->mlx_height);
	cub->img.addr = (int *)mlx_get_data_addr(cub->img.img, \
		&cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	return (cub);
}
