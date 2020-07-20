/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:27:59 by gekang            #+#    #+#             */
/*   Updated: 2020/07/20 12:02:54 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		ft_putchar(str[i]);
	}
}

void		ft_file_io(char *pathname)
{
	char	buff[BUFF_SIZE];
	int		fd;
	ssize_t	rd_size;

	if (0 < (fd = open(pathname, O_RDONLY)))
	{
		while (0 < (rd_size = read(fd, buff, BUFF_SIZE - 1)))
		{
			buff[rd_size] = '\0';
			ft_putstr(buff);
		}
		close(fd);
	}
	else
		ft_putstr("Cannot read file.\n");
	return ;
}

int			main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	ft_file_io(argv[1]);
	return (0);
}
