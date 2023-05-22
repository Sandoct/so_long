/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:25:24 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/22 16:16:20 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

void	render_entity(t_game game, t_img *til, int x_map, int y_map)
{
	int	x;
	int	y;
	int	color;
	int	sprite;

	x = -1;
	while (++x + x_map < 32 + x_map)
	{
		y = -1;
		while (++y + y_map < 32 + y_map)
		{
			if (!y && !x)
				if (game.sprite != 0 && !(game.sprite % til->sprite))
					til->direction *= -1;
			if (til->direction == -1)
				sprite = 0;
			else
				sprite = (game.sprite % til->sprite);
			color = get_pixel_color(&til->data, x + 32 * sprite, y);
			if (color != 0)
				my_pixel_put(&game.frame.data, \
						x + 16 + x_map, y + 16 + y_map, color);
		}
	}
}

void	render_number(t_game game, int x_map, int y_map, int number)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	while (++x + x_map < 20 + x_map)
	{
		y = -1;
		while (++y + y_map < 28 + y_map)
		{
			color = get_pixel_color(&game.texture.nb.data, \
					x + number * 20, y);
			if (color != 0)
				my_pixel_put(&game.frame.data, x + x_map, y + y_map, color);
		}
	}
}

static void	render_til(t_game game, int x_map, int y_map, int scale)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	while (++x + x_map < 64 + x_map)
	{
		y = -1;
		while (++y + y_map < 64 + y_map)
		{
			if (scale >= 0)
				color = get_pixel_color(&game.texture.tile.data, \
						x + scale * 64, y + 64);
			else
				color = 0;
			my_pixel_put(&game.frame.data, x + x_map, y + y_map, color);
		}
	}
}

void	render_tiles(t_game game, int x, int y, char tile)
{
	if (tile == 'E')
		render_til(game, x * 64, y * 64, 1);
	else if (tile == '1')
		render_til(game, x * 64, y * 64, 2);
	else if (tile == '2')
		render_til(game, x * 64, y * 64, -1);
	else
		render_til(game, x * 64, y * 64, 0);
}

void	render_map(t_game *game, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (int)ft_tabstrlen(map))
	{
		x = -1;
		while (++x < (int)ft_strlen(*map))
		{
			render_tiles(*game, x, y, map[y][x]);
			if (map[y][x] == 'C')
				render_entity(*game, &game->texture.collectible, \
						x * 64, y * 64);
			if (map[y][x] == 'N')
				render_entity(*game, &game->texture.npc, x * 64, y * 64);
		}
	}
	render_entity(*game, &game->texture.player, \
			game->player.disp_x * 64, game->player.disp_y * 64);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}
