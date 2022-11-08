/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_free_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:11:24 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 17:11:26 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dyn_arr_free_char(char **arr, int row)
{
	int	i;

	i = -1;
	while (++i < row)
		free(arr[i]);
	free(arr);
}
