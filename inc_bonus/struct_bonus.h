/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochichep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:06:59 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 14:25:45 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# define A 0
# define W 13
# define S 1
# define D 2
# define ESCAPE 53
# define BUFFER_SIZE 400
# define FNV "This file is not valid.\n"
# define NOTYET "Your mission is not finished yet.\n"
# define STILL "You still have some Mac to destroy!\n"
# define LINE "----------------------------------------\n"
# define WRONG "Error. Please refer to so_long's Man\n"
# define ARGV "The rules of this game are very simple.\n"
# define BRAVO "Bravo!"
# define BRAVO1 "You just wiped out"
# define BRAVO2 " 42.\n"
# define BYE "Pff... Coward!\n"
# define MIS "Remember,\nyour mission is to destroy" 
# define SION " all the Macs.\nWindows loves you.\n"
# define DEAD "Oops, you're DEAD!!!\n"

typedef struct s_map
{
	int	nbr_lines;
	int	width;
	int	height;
}			t_map;

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_tex
{
	char	*wall;
	char	*player;
	char	*player0;
	char	*player2;
	char	*exit;
	char	*collectibles;
	char	*background;
	char	*explosion;
}				t_tex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_coord	point;
}				t_img;

typedef struct s_keys {
	int	up;
	int	down;
	int	right;
	int	left;
}	t_keys;

typedef struct s_mission
{
	void	*mlx;
	void	*win;
	t_img	image;
	char	**map;
	int		co;
	int		p;
	int		ex;
	int		z;
	int		count;
	int		oyev;
	int		level;
	t_map	map_utils;
	t_tex	textures;
	t_keys	keys;
	t_coord	player_pos;
	t_coord	oyev_pos;
	t_coord	ex_pos;
	t_coord	pixels;
	t_coord	map_pixels;
	int		i;
}				t_mission;
#endif
