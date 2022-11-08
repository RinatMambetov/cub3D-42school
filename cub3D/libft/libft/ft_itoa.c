/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:45:16 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:45:18 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_ch(int n)
{
	int	cnt;

	cnt = 1;
	if (n < 0)
	{
		cnt++;
		n = -n;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_calloc(cnt_ch(n) + 1, sizeof(char));
	if (str == 0)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (n / 10 > 0)
	{
		str[i] = (char)('0' + n % 10);
		n /= 10;
		i++;
	}
	str[i] = (char)('0' + n % 10);
	return (ft_reverse(str));
}
