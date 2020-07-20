/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:19:01 by gekang            #+#    #+#             */
/*   Updated: 2020/07/20 16:18:24 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(char *str);
int		ft_is_numeric(char c);
int		ft_atoi(char *str);
void	ft_print_error(char *str);
void	ft_putstr(char *str);
int		ft_handle_error(int fd, char **argv, int i);
void	ft_banner(char **argv, int argc, int i);
void	ft_putfinal(int i, int argc);
char	*ft_write(char **argv, int argc, int option);
int		ft_count_byte_size(char **argv, int i);
int		ft_init(char **argv);
void	ft_disp_stdin(void);
int		ft_flag(int flag, char **argv, int argc, int i);
void	ft_print_illegal_off_err(char **argv);
char	*ft_get_stdin(int option);
char	*stdin_memory(int size, char *res, char buffer);
char	*ft_copy_buff(char *buff, int opt, int size);
char	*ft_output(char *str, int opt);
void	ft_display(int c_f[2], char *str, int fd);

#endif
