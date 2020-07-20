/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:47:29 by gekang            #+#    #+#             */
/*   Updated: 2020/07/20 16:16:41 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "cat.h"

void				show_error(char *exe, char *path)
{
	if (errno == 0)
		return ;
	ft_putstr(ERR, basename(exe));
	ft_putstr(ERR, ": ");
	ft_putstr(ERR, path);
	ft_putstr(ERR, ": ");
	ft_putstr(ERR, strerror(errno));
	ft_putstr(ERR, "\n");
	errno = 0;
}

void				do_cat(char *exe, char *path, int fd)
{
	unsigned int	rd_size;
	char			buff[BUFF_SIZE];

	while ((rd_size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (errno != 0)
		{
			show_error(exe, path);
			break ;
		}
		write(OUT, &buff[0], rd_size);
	}
	if (fd > 2)
		close(fd);
}

void				stdin_loop(void)
{
	do_cat(NULL, NULL, 0);
}

int					cat(char **paths, int count, int offset)
{
	int				result;
	int				fd;
	int				i;
	char			*path;

	result = 1;
	i = offset;
	while (i < count + offset)
	{
		path = paths[i];
		fd = open(path, O_RDONLY);
		if (fd < 0)
		{
			show_error(paths[0], path);
			result = 0;
		}
		else
			do_cat(paths[0], path, fd);
		i++;
	}
	return (result);
}
