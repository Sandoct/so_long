/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:53:01 by gpouzet           #+#    #+#             */
/*   Updated: 2023/04/29 20:10:40 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

static void	print_map(char **map, mlx)
{
	int	x;
	int	y;

	y = -1
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1');
				mlx_put_image_to_window(vars.mlx, vars.win,
						til.wall, x * til.wall.height, y * til.wall.lnth);
			if (map[y][x] == '0');
				mlx_put_image_to_window(vars.mlx, vars.win,
						til., x * til.wall.height, y * til.wall.lnth);
			if (map[y][x] == 'P');
				mlx_put_image_to_window(vars.mlx, vars.win,
						til.wall, x * til.wall.height, y * til.wall.lnth);
			if (map[y][x] == 'C');
				mlx_put_image_to_window(vars.mlx, vars.win,
						til.wall, x * til.wall.height, y * til.wall.lnth);
			if (map[y][x] == 'E');
				mlx_put_image_to_window(vars.mlx, vars.win,
						til.wall, x * til.wall.height, y * til.wall.lnth);
		}
	}
}

static int	game_lauch(char *file)
{
	char	**map;

	map = map(file);
	if (map == NULL)
		return (1);
	print_map(map, mlx);
}

void	character_move(t_game game, int x, int y)
{
	if (game.map[y][x] != 1)
	{
		game.pc.move++;
		ft_printf("%d\n", game.pc.move);
		if (game.map[y][x] == 'C')
		{
			game.pc.collected++;
			game.pc.footprint = game.tiles.floor;
		}
		game.pc.footprint = game.map[game.pc.x + 1][game.pc.y];
		game.pc.x = x;
		game.pc.y = y;
	}
}

int	so_long(char *file)
{
	char	**map;

	map = map_format(file);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ft_strlen(*map) * 30, ft_tabstrlen(map) * 30, "so_long");
//	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
//	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
}
