/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:36:16 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/09 15:51:07 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	main_norm(t_mission *mars)
{
	check_map(mars);
	init_window(mars);
	draw(mars);
	draw_one(mars, mars->oyev_pos.y, mars->oyev_pos.x, 'Y');
	mlx_hook(mars->win, 2, 1L << 0, key_press, mars);
	mlx_hook(mars->win, 3, 1L << 1, key_release, mars);
	mlx_hook(mars->win, 17, 0, red_cross, mars);
	mlx_loop(mars->mlx);
}

int	main(int argc, char **argv)
{
	t_mission	*mars;

	mars = NULL;
	mars = (t_mission *)malloc(sizeof(t_mission) + 1);
	ft_init(mars);
	if (argc == 3)
	{
		mars->map = parse_norm(argv[1], mars);
		mars->level = ft_atoi(argv[2]);
		main_norm(mars);
	}
	else if (argc == 2)
	{
		mars->map = parse_norm(argv[1], mars);
		main_norm(mars);
	}
	else
	{
		printf("\033[0;31m"WRONG"\033[0m"ARGV);
		free(mars);
	}
	return (0);
}
