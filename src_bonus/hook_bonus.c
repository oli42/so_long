/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:35:58 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 13:56:04 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	{
		m->keys.up = 0;
		move_oyev(m, 1);
	}
	if (keycode == S)
	{
		m->keys.down = 0;
		move_oyev(m, 1);
	}
	if (keycode == A)
	{
		m->keys.left = 0;
		move_oyev(m, 1);
	}
	if (keycode == D)
	{
		m->keys.right = 0;
		move_oyev(m, 1);
	}
	return (0);
}

int	red_cross(t_mission *m)
{
	free(m);
	exit(0);
}
