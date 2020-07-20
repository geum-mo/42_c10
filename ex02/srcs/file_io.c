/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:32:10 by gekang            #+#    #+#             */
/*   Updated: 2020/07/20 16:06:19 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	*ft_write(char **argv, int argc, int opt)
{
	int		i;
	int		fd;
	char	*str;
	int		c_f[2];

	c_f[1] = 0;
	if (!(str = (char *)malloc((opt + 1) * sizeof(char))))
		return (0);
	i = ft_init(argv);
	while (i < argc)
	{
		c_f[0] = ft_count_byte_size(argv, i) - opt;
		fd = open(argv[i], O_RDONLY);
		if (!ft_handle_error(fd, argv, i))
		{
			c_f[1] = ft_flag(c_f[1], argv, argc, i);
			ft_display(c_f, str, fd);
		}
		i++;
	}
	return (str);
}

int		ft_count_byte_size(char **argv, int i)
{
	char	c;
	int		count;
	int		fd;

	count = 0;
	fd = open(argv[i], O_RDONLY);
	if (fd > 0)
	{
		while (read(fd, &c, 1) > 0)
		{
			count++;
		}
		close(fd);
	}
	i++;
	return (count);
}

int		ft_init(char **argv)
{
	if (ft_strlen(argv[1]) >= 3)
		return (2);
	else
		return (3);
}

int		ft_flag(int flag, char **argv, int argc, int i)
{
	if (flag == 1)
		ft_putstr("\n");
	ft_banner(argv, argc, i);
	return (1);
}

void	ft_display(int c_f[2], char *str, int fd)
{
	int	j;

	j = 0;
	while (j < c_f[0] && read(fd, &str, 1) > 0)
		j++;
	j = 0;
	while (read(fd, &str[j], 1) > 0)
		j++;
	close(fd);
	str[j] = 0;
	ft_putstr(str);
}
