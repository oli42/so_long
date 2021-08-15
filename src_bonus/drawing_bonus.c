/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:11:27 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 13:52:37 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw(t_mission *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	m->pixels.y = 0;
	m->pixels.x = 0;
	while (i < (m->map_utils.height))
	{
		while (j < m->map_utils.width)
		{
			m->image.img = mlx_xpm_file_to_image(m->mlx, texture(m, \
					m->map[i][j]), &m->image.width, &m->image.height);
			if (m->image.img == NULL)
				write(1, "KO\n", 3);
			mlx_put_image_to_window(m->mlx, m->win, m->image.img, \
				m->pixels.x, m->pixels. y);
			j++;
			m->pixels.x += 32;
		}
		m->pixels.x = 0;
		j = 0;
		i++;
		m->pixels.y += 32;
	}
}

void	draw_one(t_mission *m, int y, int x, char c)
{
	m->map[y][x] = c;
	m->pixels.x = x * 32;
	m->pixels.y = y * 32;
	m->image.img = mlx_xpm_file_to_image(m->mlx, texture(m, m->map[y][x]), \
		&m->image.width, &m->image.height);
	if (m->image.img == NULL)
		write(1, "KO\n", 3);
	mlx_put_image_to_window(m->mlx, m->win, m->image.img, \
		m->pixels.x, m->pixels.y);
}
