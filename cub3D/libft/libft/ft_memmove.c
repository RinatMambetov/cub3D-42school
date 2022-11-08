/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:48:53 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:48:55 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;

	a = destination;
	b = source;
	if (a == 0 && b == 0)
		return (0);
	if (a < b)
	{
		while (n-- > 0)
			*a++ = *b++;
	}
	else
	{
		a = destination + (n - 1);
		b = source + (n - 1);
		while (n-- > 0)
			*a-- = *b--;
	}
	return (destination);
}
