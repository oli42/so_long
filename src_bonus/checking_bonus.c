/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:10:26 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 13:52:19 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_components(t_mission *m)
{
	int			i;
	int			j;
	int			k;
	const char	*sample;

	sample = "CPE01";
	i = 0;
	j = 0;
	k = 0;
	while (i < m->map_utils.height)
	{
		while (j < m->map_utils.width)
		{
			k = ft_strchr(sample, m->map[i][j]);
			if (k == 1)
			{
				printf("Error, wrong component");
				exit (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	check_size(t_mission *m)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ft_strlen(m->map[0]);
	m->map_utils.width = j;
	while (i < m->map_utils.height)
	{
		k = ft_strlen(m->map[i]);
		if (k != j)
		{
			printf("Error! not aligned");
			exit (0);
		}
		i++;
	}
	if (j == i)
		printf("Error! Wrong format");
}

void	check_walls(char c)
{
	int		checked;

	checked = 0;
	checked = ft_strchr("1", c);
	if (checked == 1)
	{
		printf("Error, found a Hole in a wall");
		exit (0);
	}
}

void	check_first_last(char *line)
{
	while (*line)
	{
		if (*line != '1')
		{
			printf("HOLE!");
			exit (0);
		}
		line++;
	}
}

void	check_map(t_mission *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_size(m);
	check_components(m);
	while (i < m->map_utils.height)
		i++;
	i--;
	j = i + 1;
	check_first_last(m->map[0]);
	check_first_last(m->map[i]);
	while (i >= 0)
	{
		check_walls(m->map[i][0]);
		i--;
	}
	i = ft_strlen(m->map[0]);
	i--;
	while (j-- && j >= 0)
		check_walls(m->map[j][i]);
	get(m);
	check(m);
}
