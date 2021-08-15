/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 12:40:29 by ochichep          #+#    #+#             */
/*   Updated: 2021/07/25 11:44:10 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mission *m)
{
	(void)m;
	printf("%d\n", keycode);
	return (0);
}

int	key_press(int keycode, t_mission *m)
{
	if (keycode == ESCAPE)
	{
		free(m);
		printf("\033[33m"BYE);
		exit (0);
	}
	if (keycode == W)
		m->keys.up = 1;
	if (keycode == S)
		m->keys.down = 1;
	if (keycode == A)
		m->keys.left = 1;
	if (keycode == D)
		m->keys.right = 1;
	moves(m);
	return (0);
}

int	key_release(int keycode, t_mission *m)
{
	if (keycode == W)
		m->keys.up = 0;
	if (keycode == S)
		m->keys.down = 0;
	if (keycode == A)
		m->keys.left = 0;
	if (keycode == D)
		m->keys.right = 0;
	return (0);
}

int	red_cross(t_mission *m)
{
	free(m);
	exit(0);
}
