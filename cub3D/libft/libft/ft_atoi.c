/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:43:26 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:43:30 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int	ans;
	int	cnt_minus;

	ans = 0;
	cnt_minus = 0;
	while (is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cnt_minus++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (ans == 214748364 && (int)(*str - '0') == 8 && cnt_minus == 1)
			return (-2147483648);
		ans = ans * 10 + (int)(*str - '0');
		str++;
	}
	if (cnt_minus == 1)
		ans = -ans;
	return (ans);
}
