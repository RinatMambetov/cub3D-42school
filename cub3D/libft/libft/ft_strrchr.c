/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:52:52 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:52:54 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*a;

	a = 0;
	if ((char)c == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str != '\0')
	{
		if (*str == (unsigned char)(c))
			a = (char *)(str);
		str++;
	}
	return (a);
}
