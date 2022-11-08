/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_mal_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:11:55 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 17:11:57 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	**ft_dyn_arr_mal_int(int row, int col)
{
	int	**arr;
	int	i;

	arr = (int **)malloc(row * sizeof(int *));
	if (!arr)
		return ((void *)0);
	i = -1;
	while (++i < row)
	{
		arr[i] = (int *)malloc(col * sizeof(int));
		if (arr[i] == (void *)0)
			return ((void *)0);
	}
	return (arr);
}
