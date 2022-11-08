/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:50:44 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:50:47 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*destination;

	destination = (ft_calloc(ft_strlen(source) + 1, sizeof(char)));
	if (destination == 0)
		return (0);
	destination = ft_memcpy(destination, source, ft_strlen(source));
	return (destination);
}
