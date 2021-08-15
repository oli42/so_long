/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:52:40 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/09 16:08:50 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mission	*open_window(t_mission *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->map_utils.width * 32, \
		m->map_utils.height * 32, "so_long");
	return (m);
}

void	load_textures(t_mission *m)
{
	m->textures.wall = "./textures/walll.xpm";
	m->textures.player = "./textures/player.xpm";
	m->textures.exit = "./textures/windows.xpm";
	m->textures.collectibles = "./textures/collectibles.xpm";
	m->textures.background = "./textures/black.xpm";
	m->textures.explosion = "./textures/Explosion.xpm";
	m->textures.player0 = "./textures/player0.xpm";
	m->textures.player2 = "./textures/player2.xpm";
}

t_mission	*init_window(t_mission *m)
{
	open_window(m);
	load_textures(m);
	return (m);
}

char	*texture(t_mission *m, char c)
{
	if (c == '1')
		return (m->textures.wall);
	if (c == '0')
		return (m->textures.background);
	if (c == 'P')
		return (m->textures.player);
	if (c == 'E')
		return (m->textures.exit);
	if (c == 'C')
		return (m->textures.collectibles);
	if (c == 'X')
		return (m->textures.explosion);
	return (NULL);
}
