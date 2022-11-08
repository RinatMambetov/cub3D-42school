/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:52:28 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:52:30 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *)(str1);
	b = (const unsigned char *)(str2);
	if (n == 0)
		return (0);
	while (n > 0 && *a != '\0' && *b != '\0')
	{
		if (*a > *b)
			return (1);
		else if (*a < *b)
			return (-1);
		a++;
		b++;
		n--;
	}
	if (n > 0 && *a == '\0' && *b != '\0')
		return (-1);
	if (n > 0 && *a != '\0' && *b == '\0')
		return (1);
	return (0);
}
