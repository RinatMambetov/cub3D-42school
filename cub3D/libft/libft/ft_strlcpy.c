/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:51:21 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:51:23 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *destination, const char *source, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = n;
	if (n != 0)
	{
		size--;
		while (size != 0 && source[i] != '\0')
		{
			destination[i] = source[i];
			i++;
			size--;
		}
	}
	if (n != 0)
		destination[i] = '\0';
	return (ft_strlen(source));
}
