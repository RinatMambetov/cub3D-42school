/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:53:12 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:53:14 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_str;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_calloc(1, 1));
	if (len > slen - start)
		len = slen - start;
	s_str = malloc((len + 1) * sizeof(char));
	if (s_str == 0)
		return (0);
	ft_memcpy(s_str, s + start, len);
	s_str[len] = '\0';
	return (s_str);
}
