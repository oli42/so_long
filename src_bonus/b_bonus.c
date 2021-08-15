/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:09:31 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 13:52:05 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_oyev_left(t_mission *m)
{
	if (m->map[m->oyev_pos.y][m->oyev_pos.x - 1] == '0')
	{
		draw_one(m, m->oyev_pos.y, m->oyev_pos.x, '0');
		draw_one(m, m->oyev_pos.y, m->oyev_pos.x - 1, 'Y');
		m->oyev_pos.x -= 1;
	}
}

void	move_oyev_right(t_mission *m)
{
	if (m->map[m->oyev_pos.y][m->oyev_pos.x + 1] == '0')
	{
		draw_one(m, m->oyev_pos.y, m->oyev_pos.x, '0');
		draw_one(m, m->oyev_pos.y, m->oyev_pos.x + 1, 'Y');
		m->oyev_pos.x += 1;
	}
}

void	move_oyev_up(t_mission *m)
{
	if (m->map[m->oyev_pos.y - 1][m->oyev_pos.x] == '0')
	{
		draw_one(m, m->oyev_pos.y, m->oyev_pos.x, '0');
		draw_one(m, m->oyev_pos.y - 1, m->oyev_pos.x, 'Y');
		m->oyev_pos.y -= 1;
	}
}

void	move_oyev_down(t_mission *m)
{
	if (m->map[m->oyev_pos.y + 1][m->oyev_pos.x] == '0')
	{
		draw_one(m, m->oyev_pos.y, m->oyev_pos.x, '0');
		draw_one(m, m->oyev_pos.y + 1, m->oyev_pos.x, 'Y');
		m->oyev_pos.y += 1;
	}
}
