/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:48:34 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:48:36 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char	*a;

	a = arr;
	while (n > 0 && *a != (unsigned char) c)
	{
		a++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((void *)(a));
}
