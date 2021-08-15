/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:06:08 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 13:51:51 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_mission	*get_expos(t_mission *m, int y, int x)
{
	m->ex++;
	m->ex_pos.y = y;
	m->ex_pos.x = x;
	m->oyev_pos.y = y + 1;
	m->oyev_pos.x = x + 1;
	return (m);
}

int	move_oyev(t_mission *m, int mvt)
{
	if (mvt == 1 || mvt == 2 || mvt == 3 || mvt == 4)
	{
		dead(m);
		if (m->oyev_pos.y == m->player_pos.y)
		{
			if (m->oyev_pos.x > m->player_pos.x)
				move_oyev_left(m);
			else if (m->oyev_pos.x < m->player_pos.x)
				move_oyev_right(m);
			return (0);
		}
		else if (m->oyev_pos.y > m->player_pos.y)
			combo1(m);
		else if (m->oyev_pos.y < m->player_pos.y)
			combo2(m);
	}
	return (0);
}

void	dead(t_mission *m)
{
	if ((m->map[m->oyev_pos.y][m->oyev_pos.x + 1] == 'P') \
			|| (m->map[m->oyev_pos.y][m->oyev_pos.x - 1] == 'P') \
			|| (m->map[m->oyev_pos.y + 1][m->oyev_pos.x] == 'P') \
			|| (m->map[m->oyev_pos.y - 1][m->oyev_pos.x] == 'P'))
	{
		 printf("\033[0;31m"DEAD);
		 exit (0);
	}
}

void	combo1(t_mission *m)
{
	move_oyev_up(m);
	if (m->level == 2 || m->level == 3)
	{	
		if (m->oyev_pos.x < m->player_pos.x)
			move_oyev_right(m);
	}
	if (m->level == 3)
	{
		if (m->oyev_pos.x > m->player_pos.x)
			move_oyev_left(m);
	}
}

void	combo2(t_mission *m)
{
	move_oyev_down(m);
	if (m->level == 2 || m->level == 3)
	{
		if (m->oyev_pos.x < m->player_pos.x)
			move_oyev_right(m);
	}
	if (m->level == 3)
	{
		if (m->oyev_pos.x > m->player_pos.x)
			move_oyev_left(m);
	}
}
