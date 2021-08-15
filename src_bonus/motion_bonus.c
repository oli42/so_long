/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:24:49 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/09 16:01:48 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moves(t_mission *m)
{
	if (m->keys.up == 1)
	{
		move_up(m);
	}
	else if (m->keys.down == 1)
	{
		move_down(m);
	}
	else if (m->keys.left == 1)
	{
		move_left(m);
	}
	else if (m->keys.right == 1)
		move_right(m);
}

void	move_up(t_mission *m)
{
	if (m->map[m->player_pos.y - 1][m->player_pos.x] == 'C')
	{
		m->co -= 1;
		draw_one(m, m->player_pos.y - 1, m->player_pos.x, '0');
		draw_one(m, m->player_pos.y - 1, m->player_pos.x, 'X');
	}
	if (m->map[m->player_pos.y - 1][m->player_pos.x] == 'E')
	{
		if (m->co == 0)
		{
			draw_one(m, m->player_pos.y - 1, m->player_pos.x, 'P');
			draw_one(m, m->player_pos.y, m->player_pos.x, '0');
			ciao(m);
		}
		else
			printf("\033[0;31m"NOTYET"\033[0;31m"STILL"\033[0m"LINE);
	}
	if (m->map[m->player_pos.y - 1][m->player_pos.x] == 'X' \
		|| m->map[m->player_pos.y - 1][m->player_pos.x] == '0' )
	{
		draw_one(m, m->player_pos.y - 1, m->player_pos.x, 'P');
		draw_one(m, m->player_pos.y, m->player_pos.x, '0');
		m->player_pos.y -= 1;
		write_move(m, "You moved up\n");
	}
}

void	move_down(t_mission *m)
{
	if (m->map[m->player_pos.y + 1][m->player_pos.x] == 'C')
	{
		m->co -= 1;
		draw_one(m, m->player_pos.y + 1, m->player_pos.x, '0');
		draw_one(m, m->player_pos.y + 1, m->player_pos.x, 'X');
	}
	if (m->map[m->player_pos.y + 1][m->player_pos.x] == 'E')
	{
		if (m->co == 0)
		{
			draw_one(m, m->player_pos.y + 1, m->player_pos.x, 'P');
			draw_one(m, m->player_pos.y, m->player_pos.x, '0');
			ciao(m);
		}
		else
			printf("\033[0;31m"NOTYET"\033[0;31m"STILL"\033[0m"LINE);
	}
	if (m->map[m->player_pos.y + 1][m->player_pos.x] == 'X' \
		|| m->map[m->player_pos.y + 1][m->player_pos.x] == '0' )
	{
		draw_one(m, m->player_pos.y + 1, m->player_pos.x, 'P');
		draw_one(m, m->player_pos.y, m->player_pos.x, '0');
		m->player_pos.y += 1;
		write_move(m, "You moved down\n");
	}
}

void	move_left(t_mission *m)
{
	if (m->map[m->player_pos.y][m->player_pos.x - 1] == 'C')
	{
		m->co -= 1;
		draw_one(m, m->player_pos.y, m->player_pos.x - 1, '0');
		draw_one(m, m->player_pos.y, m->player_pos.x - 1, 'X');
	}
	if (m->map[m->player_pos.y][m->player_pos.x - 1] == 'E')
	{
		if (m->co == 0)
		{
			draw_one(m, m->player_pos.y, m->player_pos.x - 1, 'P');
			draw_one(m, m->player_pos.y, m->player_pos.x, '0');
			ciao(m);
		}
		else
			printf("\033[0;31m"NOTYET"\033[0;31m"STILL"\033[0m"LINE);
	}
	if (m->map[m->player_pos.y][m->player_pos.x - 1] == 'X' \
		|| m->map[m->player_pos.y][m->player_pos.x - 1] == '0' )
	{	
		draw_one(m, m->player_pos.y, m->player_pos.x - 1, 'P');
		draw_one(m, m->player_pos.y, m->player_pos.x, '0');
		m->player_pos.x -= 1;
		write_move(m, "You moved on the left\n");
	}
}

void	move_right(t_mission *m)
{
	if (m->map[m->player_pos.y][m->player_pos.x + 1] == 'C')
	{
		m->co -= 1;
		draw_one(m, m->player_pos.y, m->player_pos.x + 1, '0');
		draw_one(m, m->player_pos.y, m->player_pos.x + 1, 'X');
	}
	if (m->map[m->player_pos.y][m->player_pos.x + 1] == 'E')
	{
		if (m->co == 0)
		{	
			draw_one(m, m->player_pos.y, m->player_pos.x + 1, 'P');
			draw_one(m, m->player_pos.y, m->player_pos.x, '0');
			ciao(m);
		}
		else
			printf("\033[0;31m"NOTYET"\033[0;31m"STILL"\033[0m"LINE);
	}
	if (m->map[m->player_pos.y][m->player_pos.x + 1] == 'X' \
		|| m->map[m->player_pos.y][m->player_pos.x + 1] == '0' )
	{
		draw_one(m, m->player_pos.y, m->player_pos.x + 1, 'P');
		draw_one(m, m->player_pos.y, m->player_pos.x, '0');
		m->player_pos.x += 1;
		write_move(m, "You moved on the right\n");
	}
}
