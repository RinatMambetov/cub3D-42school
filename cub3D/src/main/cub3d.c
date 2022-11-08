/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:07:00 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 18:07:08 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	cub_error(char *error)
{
	printf("%s\n", error);
	exit(1);
}

int	ft_update(void *param)
{
	t_cub3d		*cub;

	cub = (t_cub3d *)param;
	update_move(cub);
	if (cub->mouse > 0)
		cub->mouse--;
	if (cub->mouse < 0)
		cub->mouse++;
	cub_draw(cub);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub;

	if (argc == 2)
	{
		cub = cub_init(argv[1]);
		cub_hook(cub);
		mlx_loop_hook(cub->mlx, ft_update, (void *)cub);
		mlx_loop(cub->mlx);
	}
	else
		cub_error("Error: Wrong enter");
}
