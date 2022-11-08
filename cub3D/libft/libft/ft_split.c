/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:50:03 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:50:05 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_char(char const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i > 0 && s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
			cnt++;
		i++;
	}
	return (cnt);
}

static void	ft_free(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_cnt_j(char const *s, char c)
{
	while (*s == c)
		s++;
	if (ft_strchr(s, c) == 0)
		return ((int)ft_strlen(s));
	else
		return ((int)(ft_strchr(s, c) - s));
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		cnt;
	int		i;

	cnt = cnt_char(s, c);
	arr = malloc((cnt + 1) * sizeof(char *));
	if (arr == 0)
		return (0);
	arr[cnt] = 0;
	i = 0;
	while (i < cnt)
	{
		arr[i] = ft_calloc(ft_cnt_j(s, c) + 1, sizeof(char));
		if (arr[i] == 0)
		{
			ft_free(arr, i);
			return (0);
		}
		while (*s == c)
			s++;
		arr[i] = ft_memcpy(arr[i], s, ft_cnt_j(s, c));
		arr[i++][ft_cnt_j(s, c)] = '\0';
		s += ft_cnt_j(s, c) + 1;
	}
	return (arr);
}
