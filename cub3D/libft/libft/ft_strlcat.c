/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:51:09 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:51:12 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t n)
{
	size_t	destination_len;
	size_t	i;
	size_t	source_len;

	destination_len = ft_strlen(destination);
	i = destination_len;
	source_len = ft_strlen(source);
	if (destination_len + 1 < n)
	{
		while (*source != '\0' && i + 1 < n)
		{
			destination[i] = *source;
			i++;
			source++;
		}
		destination[i] = '\0';
	}
	if (destination_len > n)
		return (n + source_len);
	return (destination_len + source_len);
}
