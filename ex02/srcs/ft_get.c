/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:50:07 by gekang            #+#    #+#             */
/*   Updated: 2020/07/20 14:50:08 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	*ft_get_stdin(int opt)
{
	char	buff[1024];
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (read(0, &buff[size], 1) != 0)
		size++;
	res = ft_copy_buff(buff, opt, size);
	return (res);
}

char	*ft_copy_buff(char *buff, int opt, int size)
{
	char	*res;
	int		i;

	i = 0 - 1;
	if (!(res = (char *)malloc((opt + 1) * sizeof(char))))
		return (0);
	if (size - opt > 0)
	{
		while (buff[size - opt + ++i])
			res[i] = buff[size - opt + i];
		res[i] = '\0';
	}
	else
		return (buff);
	return (res);
}
