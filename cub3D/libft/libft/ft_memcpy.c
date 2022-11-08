/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:55:48 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:55:50 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t	i;

	i = 0;
	if (destination == 0 && source == 0)
		return (0);
	while (i < n)
	{
		((unsigned char *)destination)[i] = ((unsigned char *)source)[i];
		i++;
	}
	return (destination);
}
