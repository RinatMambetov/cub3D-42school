/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:08:57 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:09:03 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	cub_draw(t_cub3d *cub)
{
	cub_draw_wall(cub);
	cub_draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
	return (1);
}
