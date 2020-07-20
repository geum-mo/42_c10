/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:20:54 by gekang            #+#    #+#             */
/*   Updated: 2020/07/20 14:54:44 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_print_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int		ft_handle_error(int fd, char **argv, int i)
{
	if (fd < 0)
	{
		ft_print_err(basename(argv[0]));
		ft_print_err(": ");
		ft_print_err(argv[i]);
		ft_print_err(": ");
		ft_print_err(strerror(errno));
		ft_print_err("\n");
		return (1);
	}
	return (0);
}

void	ft_banner(char **argv, int argc, int i)
{
	int	size;

	size = ft_strlen(argv[1]);
	if ((size >= 3 && argc > 3) || argc > 4)
	{
		ft_putstr("==> ");
		ft_putstr(argv[i]);
		ft_putstr(" <==");
		ft_putstr("\n");
	}
}

void	ft_print_illegal_off_err(char **argv)
{
	ft_print_err(basename(argv[0]));
	ft_print_err(": ");
	ft_print_err("illegal offset -- ");
	ft_print_err(argv[2]);
	ft_print_err("\n");
}
