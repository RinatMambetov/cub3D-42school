/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoa.c                                          :+:      :+:    :+:   */
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
	while (n / 8 > 0)
	{
		n /= 8;
		cnt++;
	}
	return (cnt);
}

char	*ft_otoa(unsigned int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(cnt_ch(n) + 1, sizeof(char));
	if (str == 0)
		return (0);
	while (n / 8 > 0)
	{
		str[i] = (char)('0' + n % 8);
		n /= 8;
		i++;
	}
	str[i] = (char)('0' + n % 8);
	return (ft_reverse(str));
}
