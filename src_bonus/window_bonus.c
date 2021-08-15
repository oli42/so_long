/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:24:37 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/09 16:17:17 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	m->textures.player = "./textures/player0.xpm";
	m->textures.exit = "./textures/windows.xpm";
	m->textures.collectibles = "./textures/collectibles.xpm";
	m->textures.background = "./textures/black.xpm";
	m->textures.explosion = "./textures/Explosion.xpm";
	m->textures.player0 = "./textures/player0.xpm";
	m->textures.player2 = "./textures/oyev32.xpm";
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
	if (c == 'Y')
		return (m->textures.player2);
	return (NULL);
}
