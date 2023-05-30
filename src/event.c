/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:24:32 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/30 17:15:20 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->texture.tile.img);
	mlx_destroy_image(game->mlx, game->texture.player.img);
	mlx_destroy_image(game->mlx, game->texture.collectible.img);
	mlx_destroy_image(game->mlx, game->frame.img);
	mlx_loop_end(game->mlx);
	return (0);
}

static int	player_move(t_game *game, int x, int y)
{
	if (game->map[game->player.y + y][game->player.x + x] == '1')
		return (1);
	if (game->map[game->player.y + y][game->player.x + x] == 'C')
	{
		game->map[game->player.y + y][game->player.x + x] = '0';
		game->player.collected++;
	}
	game->player.move++;
	ft_printf("move : %d.\n", game->player.move);
	render_tiles(*game, game->player.x, game->player.y, game->player.footprint);
	game->player.footprint = game->map[game->player.y + y][game->player.x + x];
	game->player.x += x;
	game->player.y += y;
	render_tiles(*game, game->player.x, game->player.y, \
			game->map[game->player.y][game->player.x]);
	render_entity(*game, game->texture.player, \
			game->player.x * 64, game->player.y * 64);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	if (game->player.collected == game->collectible)
		if (game->map[game->player.y][game->player.x] == 'E')
			close_game(game);
	return (0);
}

int	hook_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 65362 || keycode == 119)
		player_move(game, 0, -1);
	if (keycode == 65364 || keycode == 115)
		player_move(game, 0, 1);
	if (keycode == 65361 || keycode == 97)
		player_move(game, -1, 0);
	if (keycode == 65363 || keycode == 100)
		player_move(game, 1, 0);
	return (0);
}
