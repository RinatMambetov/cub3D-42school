/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:52:38 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:52:40 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	findlen;

	i = 0;
	findlen = ft_strlen(find);
	if ((*find == '\0' && n <= 0) || findlen == 0)
		return ((char *)(str));
	while (*str != '\0' && i + findlen <= n)
	{
		if (ft_memcmp(str, find, findlen) == 0)
			return ((char *)(str));
		str++;
		i++;
	}
	return (0);
}
