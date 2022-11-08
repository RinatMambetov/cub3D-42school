/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:45:16 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:45:18 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_ch(size_t n)
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

char	*ft_ptoa(void *p)
{
	size_t	n;
	int		len;
	char	*str;
	int		i;

	if (p == 0)
		return (ft_strdup("(nil)"));
	n = (size_t)(p);
	len = cnt_ch(n);
	i = len + 2;
	str = ft_calloc(len + 3, sizeof(char));
	if (str == 0)
		return (0);
	while (i > 1)
	{
		str[i - 1] = hex(n % 16);
		n /= 16;
		i--;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}
