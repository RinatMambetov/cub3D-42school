/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:53:01 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:53:02 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	begin_str;
	size_t	end_str;

	begin_str = 0;
	end_str = ft_strlen(s1);
	while (ft_strchr(set, s1[begin_str]) != 0)
		begin_str++;
	while (ft_strchr(set, s1[end_str]) != 0)
		end_str--;
	str = ft_substr(s1, begin_str, end_str - begin_str + 1);
	return (str);
}
