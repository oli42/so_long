/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:23:50 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/09 16:24:00 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "struct.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include "get_next_line.h"
int			key_hook(int keycode, t_mission *m);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strchr(const char *s, char c);
int			open_file(char *input);
char		**parse(char *input, t_mission *m);
char		**parse_norm(char *input, t_mission *m);
int			norm(char *input, t_mission *m);
void		ft_init(t_mission *m);
void		draw(t_mission *m);
void		draw_one(t_mission *m, int x, int y, char c);
void		ft_putstr_fd(char *str, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putchar_fd(char a, int fd);
void		check_map(t_mission *m);
void		check_walls(char c);
void		check_components(t_mission *m);
void		check_first_last(char *line);
void		check_size(t_mission *m);
t_mission	*init_window(t_mission *m);
t_mission	*open_window(t_mission *m);
void		load_textures(t_mission *m);
char		*texture(t_mission *m, char c);
t_mission	*get(t_mission *m);
t_mission	*get_ppos(t_mission *m, int y, int x);
void		check(t_mission *m);
void		moves(t_mission *m);
void		move_up(t_mission *m);
void		move_down(t_mission *m);
void		move_left(t_mission *m);
void		move_right(t_mission *m);
void		write_move(t_mission *m, char *str);
int			key_hook(int keycode, t_mission *m);
int			key_press(int keycode, t_mission *m);
int			key_release(int keycode, t_mission *m);
int			red_cross(t_mission *m);
void		ciao(t_mission *m);
void		empty(void);
#endif
