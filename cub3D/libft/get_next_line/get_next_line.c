/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:13:48 by hregina           #+#    #+#             */
/*   Updated: 2022/06/22 17:13:50 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_reminder(char *rem, char **line)
{
	char	*p_n;

	p_n = ((void *)0);
	if (*rem)
	{
		p_n = ft_strchr(rem, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(rem);
			rem = ft_strcpy(rem, ++p_n);
		}
		else
		{
			*line = ft_strdup(rem);
			*rem = '\0';
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

static int	return_and_free_line(int r, char **line)
{
	if (r < 0)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (*line == (void *)0)
	{
		free(*line);
		*line = NULL;
	}
	return (0);
}

static int	gnl_read(char *rem, char *buf, char **line, int fd)
{
	char	*tmp;
	char	*p_n;
	int		r;

	r = 1;
	p_n = ((void *)0);
	while (!p_n && r)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
			return (return_and_free_line(r, line));
		buf[r] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			rem = ft_strcpy(rem, ++p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		if (!(*line))
			return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || \
		read(fd, buffer, 0) != 0)
	{
		if (line)
			*line = ((void *)0);
		return (-1);
	}
	tmp = gnl_reminder(remainder, line);
	if (!(*line))
		return (-1);
	if (tmp)
		return (1);
	return (gnl_read(remainder, buffer, line, fd));
}
