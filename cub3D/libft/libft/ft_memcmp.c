/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:48:45 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:48:47 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)(arr1);
	b = (unsigned char *)(arr2);
	while (n > 0)
	{
		if (*a > *b)
			return (*a - *b);
		else if (*a < *b)
			return (*a - *b);
		a++;
		b++;
		n--;
	}
	return (0);
}
