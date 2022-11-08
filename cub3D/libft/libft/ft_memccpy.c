/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:48:20 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:48:22 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;

	a = destination;
	b = source;
	while (n > 0 && *b != (unsigned char)c)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	if (n == 0)
		return (0);
	else
	{
		*a = *b;
		a++;
		return (a);
	}
}
