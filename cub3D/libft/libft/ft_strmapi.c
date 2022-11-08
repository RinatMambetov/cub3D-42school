/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:52:13 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:52:15 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	str = ft_calloc(slen + 1, sizeof(char));
	if (str == 0)
		return (0);
	while (i < slen)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
