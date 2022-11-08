/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:12:04 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 17:12:06 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_split(char	**tmp)
{
	int	i;

	if (!tmp)
		return ;
	i = -1;
	while (tmp[++i])
		free (tmp[i]);
	free(tmp);
}
