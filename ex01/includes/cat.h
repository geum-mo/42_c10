/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:39:03 by gekang            #+#    #+#             */
/*   Updated: 2020/07/20 16:16:23 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# define IN 0
# define OUT 1
# define ERR 2
# define BUFF_SIZE 1024

void	stdin_loop();

int		cat(char **paths, int count, int offset);

void	ft_putstr(int fd, char *str);

#endif
