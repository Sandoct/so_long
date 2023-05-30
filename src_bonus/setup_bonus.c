/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:34:26 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/30 16:35:47 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

void	scan_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->sprite = 1;
	game->collectible = 0;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				game->collectible++;
			if (game->map[y][x] == 'P')
				set_player(&game->player, x, y);
		}
	}
}

void	player_position(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map_disp[++y])
	{
		x = -1;
		while (game->map_disp[y][++x])
		{
			if (game->map_disp[y][x] == 'P')
			{
				game->player.disp_x = x;
				game->player.disp_y = y;
			}
		}
	}
}
