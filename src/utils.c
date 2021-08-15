/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:25:23 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/10 16:05:38 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mission	*get(t_mission *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m->map_utils.height)
	{
		while (j < m->map_utils.width)
		{
			if (m->map[i][j] == 'P')
				get_ppos(m, i, j);
			else if (m->map[i][j] == 'E')
				m->ex++;
			else if (m->map[i][j] == 'C')
				m->co++;
			else if (m->map[i][j] == '0')
				m->z++;
			j++;
		}
		j = 0;
		i++;
	}
	return (m);
}

t_mission	*get_ppos(t_mission *m, int y, int x)
{
	m->p++;
	m->player_pos.y = y;
	m->player_pos.x = x;
	return (m);
}

void	check(t_mission *m)
{
	if (m->p != 1)
	{
		printf("Error, too many players\n");
		exit (0);
	}
	if (m->ex == 0)
	{
		printf("Error, no exit\n");
		exit (0);
	}
	if (m->co == 0)
	{
		printf("Error, no collectibles\n");
		exit (0);
	}
	if (m->z == 0)
	{
		printf("Error, no empty space\n");
		exit (0);
	}
}

void	write_move(t_mission *m, char *str)
{
	m->count++;
	ft_putstr_fd(str, 1);
	if (m->count == 1)
	{
		ft_putstr_fd("Congratulations, that's your first move.\n", 1);
		printf("\033[33m"MIS);
		printf("\033[33m"SION);
		printf("\033[0m"LINE);
	}
	if (m->count != 1)
	{
		ft_putstr_fd("Now you totalize - ", 1);
		ft_putnbr_fd(m->count, 1);
		ft_putstr_fd(" - moves.\n", 1);
		write(1, "----------------------------------------\n", 41);
	}
}

void	ciao(t_mission *m)
{
	m->count++;
	printf("\033[0;31m"BRAVO"\033[0m"BRAVO1"\033[33m"BRAVO2);
	free(m);
	exit (0);
}
