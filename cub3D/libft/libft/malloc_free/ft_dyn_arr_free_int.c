/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_free_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:11:34 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 17:11:35 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dyn_arr_free_int(int **arr, int row)
{
	int	i;

	i = -1;
	while (++i < row)
		free(arr[i]);
	free(arr);
}
