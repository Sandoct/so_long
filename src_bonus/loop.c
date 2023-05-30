/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:56:15 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/30 17:52:42 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "so_long.h"
#include <time.h>

static void	npc_move(t_game *game, int x, int y)
{
	int	r;

	r = rand() % 8;
	if (r == 1 && game->map[y - 1][x] == '0' && y - 1 != game->player.y)
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'N';
	}
	if (r == 3 && game->map[y][x + 1] == '0' && (x + 1) != game->player.x)
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'N';
	}
	if (r == 5 && game->map[y + 1][x] == '0' && (y + 1) != game->player.y)
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'N';
	}
	if (r == 7 && game->map[y][x - 1] == '0' && (x - 1) != game->player.x)
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'N';
	}
}

static void	patrol(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'N')
				npc_move(game, x, y);
		}
	}
}

int	sprite(t_game *game)
{
	clock_t			t;
	static clock_t	n = 0;
	static clock_t	p = 0;

	t = clock();
	if (n == 0)
		n = t;
	if (p == 0)
		p = t;
	if (((t - p) / (CLOCKS_PER_SEC / 1)) == 1)
		patrol(game);
	if (((t - p) / (CLOCKS_PER_SEC / 1)) == 1)
		p = t;
	if (((t - n) / (CLOCKS_PER_SEC / 20)) == 1)
	{
		if (game->sprite++ >= 128)
			game->sprite = 1;
		freetab(game->map_disp);
		displayed_map(game, game->player.disp_x, game->player.disp_y);
		if (game->map_disp == NULL)
			return (1);
		move_on_screen(game, game->player.move);
		n = t;
	}
	return (0);
}
