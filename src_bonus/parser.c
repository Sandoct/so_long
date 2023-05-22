/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:47:54 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/16 13:50:00 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

static int	shape(char **map, int width, int height)
{
	int	y;

	y = 0;
	while (y < height)
		if ((int)ft_strlen(map[y++]) != width)
			return (ft_putstr_fd("Error wrong map shape\n", 2));
	return (0);
}

static int	tokens(char c)
{
	static int	start = 0;
	static int	exit = 0;
	static int	collectible = 0;

	if (c == 'P')
		start++;
	else if (c == 'E')
		exit++;
	else if (c == 'C')
		collectible ++;
	else if (start > 1)
		return (ft_putstr_fd("Error where do i start\n", 2));
	else if (exit > 1)
		return (ft_putstr_fd("Error to many exit\n", 2));
	else if (collectible < 1)
		return (ft_putstr_fd("Error not enough collectible\n", 2));
	if (c == '1')
	{
		start = 0;
		exit = 0;
		collectible = 0;
	}
	return (0);
}

static int	content(char **map, int width, int height)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
				if (map[y][x] != '1')
					return (ft_putstr_fd("Error map not closed\n", 2));
			if (map[y][x] == 'E' || map[y][x] == 'P' || map[y][x] == 'C')
				tokens(map[y][x]);
			else if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'N')
				return (ft_putstr_fd("Error invalide content\n", 2));
		}
	}
	if (tokens(map[0][0]))
		return (1);
	return (0);
}

static int	playable(char **map, int x, int y)
{
	int	exit;

	exit = 1;
	if (map[y][x] == 'E')
		exit = 0;
	map[y][x] = '1';
	if (map[y - 1][x] != '1')
		if (!playable(map, x, y - 1))
			exit = 0;
	if (map[y][x - 1] != '1')
		if (!playable(map, x - 1, y))
			exit = 0;
	if (map[y + 1][x] != '1')
		if (!playable(map, x, y + 1))
			exit = 0;
	if (map[y][x + 1] != '1')
		if (!playable(map, x + 1, y))
			exit = 0;
	return (exit);
}

int	parser(char **map)
{
	int		width;
	int		height;
	t_pc	pc;

	width = ft_strlen(map[0]);
	height = ft_tabstrlen(map);
	if (height < 3 || width < 3)
		return (1);
	if (shape(map, width, height))
		return (1);
	if (content(map, width, height))
		return (1);
	pc = player_position_parser(map);
	if (playable(map, pc.x, pc.y) || collectible(map))
		return (ft_putstr_fd("Error no valide path\n", 2));
	return (0);
}
