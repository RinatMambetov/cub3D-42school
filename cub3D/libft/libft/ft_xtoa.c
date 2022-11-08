/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:45:16 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:45:18 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_ch(unsigned int n)
{
	int	cnt;

	cnt = 1;
	while (n / 16 > 0)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

static char	hex(unsigned int d)
{
	if (d < 10)
		return ((char)('0' + d));
	return ((char)('a' + d - 10));
}

char	*ft_xtoa(unsigned int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(cnt_ch(n) + 1, sizeof(char));
	if (str == 0)
		return (0);
	while (n / 16 > 0)
	{
		str[i] = hex(n % 16);
		n /= 16;
		i++;
	}
	str[i] = hex(n % 16);
	return (ft_reverse(str));
}
