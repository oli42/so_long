/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 12:41:28 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 13:25:58 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mission	*mars;

	mars = NULL;
	mars = (t_mission *)malloc(sizeof(t_mission) + 1);
	ft_init(mars);
	if (argc == 2)
	{
		mars->map = parse_norm(argv[1], mars);
		check_map(mars);
		init_window(mars);
		draw(mars);
		mlx_hook(mars->win, 2, 1L << 0, key_press, mars);
		mlx_hook(mars->win, 3, 1L << 1, key_release, mars);
		mlx_hook(mars->win, 17, 0, red_cross, mars);
		mlx_loop(mars->mlx);
	}
	else
	{
		printf("\033[0;31m"WRONG"\033[0m"ARGV);
		free(mars);
	}
	return (0);
}
