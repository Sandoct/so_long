/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:25:24 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/22 15:37:37 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

void	render_entity(t_game game, t_img til, int x_map, int y_map)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	while (++x + x_map < 32 + x_map)
	{
		y = -1;
		while (++y + y_map < 32 + y_map)
		{
			color = get_pixel_color(&til.data, x, y);
			if (color != 0)
				my_pixel_put(&game.frame.data, \
						x + 16 + x_map, y + 16 + y_map, color);
		}
	}
}

static void	render_til(t_game game, int x_map, int y_map, int scale)
{
	int	x;
	int	y;

	x = -1;
	while (++x + x_map < 64 + x_map)
	{
		y = -1;
		while (++y + y_map < 64 + y_map)
		{
			my_pixel_put(&game.frame.data, x + x_map, y + y_map, \
					get_pixel_color(&game.texture.tile.data, \
						x + scale * 64, y + 64));
		}
	}
}

void	render_tiles(t_game game, int x, int y, char tile)
{
	if (tile == 'E')
		render_til(game, x * 64, y * 64, 1);
	else if (tile == '1')
		render_til(game, x * 64, y * 64, 2);
	else
		render_til(game, x * 64, y * 64, 0);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->collectible = 0;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			render_tiles(*game, x, y, game->map[y][x]);
			if (game->map[y][x] == 'C')
			{
				render_entity(*game, game->texture.collectible, x * 64, y * 64);
				game->collectible++;
			}
			if (game->map[y][x] == 'P')
			{
				set_player(&game->player, x, y);
				render_entity(*game, game->texture.player, x * 64, y * 64);
			}
		}
	}
}
