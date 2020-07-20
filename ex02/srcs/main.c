/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:01:01 by gekang            #+#    #+#             */
/*   Updated: 2020/07/20 16:05:49 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		main(int argc, char **argv)
{
	int		opt;
	char	*str;

	if (argc < 2)
	{
		return (0);
	}
	opt = ft_atoi(argv[2]);
	if (opt == -1)
	{
		ft_print_illegal_off_err(argv);
		return (0);
	}
	if (argc == 3)
	{
		ft_putstr(ft_get_stdin(opt));
	}
	else
		str = ft_write(argv, argc, opt);
	return (0);
}
