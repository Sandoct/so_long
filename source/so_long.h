/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:10:40 by gpouzet           #+#    #+#             */
/*   Updated: 2023/04/29 20:23:26 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
/*
typedef struct s_img;
{
	void	img;
	int		width;
	int		height;
}			t_img;

typedef struct s_til
{
	t_img	*wall;
	t_img	*player;
	t_img	*exit;
	t_img	*start;
	t_img	*collectible;
	t_img	*floor;
}			t_til;
*/
typedef struct s_playable_character
{
	int		x;
	int		y;
	int		collected;
//	t_img	footprint;
}			t_pc;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
//	t_til	tiles;
	t_pc	pc;
	int		collectible;
}			t_game;

void	freetab(char **tab);
char	**map_format(char *file);
int		parser(char **map);
int		collectible(char **map);
t_pc	player_position(char **map);
#endif
