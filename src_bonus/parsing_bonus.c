/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:02:03 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/09 16:02:06 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	open_file(char *input)
{
	int		fd;
	char	*copy;

	copy = ft_strrchr(input, '.');
	if (copy == NULL || ft_strcmp(".ber", copy) != 0)
	{
		printf(FNV);
		exit(EXIT_FAILURE);
	}
	errno = 0;
	fd = open(input, O_RDONLY);
	if (errno != 0 || fd == -1)
	{
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	norm(char *input, t_mission *m)
{
	int		r;
	int		i;
	int		fd;
	char	*line;

	fd = 0;
	i = 0;
	r = 1;
	fd = open_file(input);
	while (r > 0)
	{
		r = get_next_line(fd, &line);
		if (line != NULL && ft_strlen(line) > 0)
		{
			i++;
			free(line);
		}
	}
	if (i == 0)
		empty();
	free(line);
	m->map_utils.height = i;
	fd = open_file(input);
	return (fd);
}

char	**parse_norm(char *input, t_mission *m)
{
	char	**dst;
	int		r;
	int		fd;
	char	*line;

	line = NULL;
	dst = NULL;
	r = 1;
	fd = norm(input, m);
	dst = (char **)malloc(sizeof(char *) * m->map_utils.height + 1);
	while (r > 0)
	{
		r = get_next_line(fd, &line);
		if (line != NULL && ft_strlen(line) > 0)
		{
			dst[m->i] = line;
			dst[m->i] = ft_strdup(line);
			free(line);
			m->i++;
		}
	}
	free(line);
	close(fd);
	return (dst);
}

void	ft_init(t_mission *m)
{
	m->p = 0;
	m->ex = 0;
	m->co = 0;
	m->z = 0;
	m->i = 0;
	m->level = 0;
	m->keys.up = 0;
	m->keys.down = 0;
	m->keys.right = 0;
	m->keys.left = 0;
	m->count = 0;
	m->oyev = 2;
	m->map_pixels.x = 1100;
	m->map_pixels.y = 810;
}

void	empty(void)
{
	printf("Empty file\n");
	exit(0);
}
