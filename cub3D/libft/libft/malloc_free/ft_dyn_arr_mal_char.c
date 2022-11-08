/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_mal_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:11:48 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 17:11:50 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_dyn_arr_mal_char(int row, int col)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(row * sizeof(char *));
	if (!arr)
		return ((void *)0);
	i = -1;
	while (++i < row)
	{
		arr[i] = (char *)malloc(col * sizeof(char));
		if (arr[i] == (void *)0)
			return ((void *)0);
	}
	return (arr);
}
