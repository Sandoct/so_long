/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:57:00 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/22 15:37:17 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "so_long.h"

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_img
{
	void	*img;
	t_data	data;
	int		width;
	int		height;
}			t_img;

typedef struct s_texture
{
	t_img	tile;
	t_img	player;
	t_img	collectible;
}			t_txt;

typedef struct s_playable_character
{
	int		x;
	int		y;
	int		move;
	int		collected;
	char	footprint;
}			t_pc;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	size_t	map_width;
	size_t	map_height;
	t_img	frame;
	t_txt	texture;
	t_pc	player;
	int		collectible;
}			t_game;
#endif
