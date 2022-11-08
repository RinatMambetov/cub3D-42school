/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:45:16 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:45:18 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *str)
{
	size_t	begin;
	size_t	end;
	char	temp;

	begin = 0;
	end = ft_strlen(str) - 1;
	temp = '0';
	if (str[0] == '-')
		begin++;
	while (begin < end)
	{
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
	return (str);
}
