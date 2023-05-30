/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:24:32 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/30 17:57:09 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

static int	scroll(t_game *game)
{
	game->player.footprint = game->map[game->player.y][game->player.x];
	freetab(game->map_disp);
	displayed_map(game, game->player.disp_x, game->player.disp_y);
	if (game->map_disp == NULL)
		return (1);
	return (0);
}

static void	player_move(t_game *game, int x, int y)
{
	game->player.disp_x += x;
	game->player.disp_y += y;
}

static int	player_action(t_game *game, int x, int y)
{
	if (game->map[game->player.y + y][game->player.x + x] == '1')
		return (0);
	if (game->map[game->player.y + y][game->player.x + x] == 'N')
		return (close_game(game));
	if (game->map[game->player.y + y][game->player.x + x] == 'C')
	{
		game->map[game->player.y + y][game->player.x + x] = '0';
		game->map_disp[game->player.disp_y + y][game->player.disp_x + x] = '0';
		game->player.collected++;
	}
	game->player.x += x;
	game->player.y += y;
	if (game->player.disp_y + y < S_HEIGHT - 2 && game->player.disp_y + y > 1)
		if (game->player.disp_x + x < S_WIDTH - 2
			&& game->player.disp_x + x > 1)
			player_move(game, x, y);
	if (scroll(game))
		return (1);
	move_on_screen(game, game->player.move++);
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
		player_action(game, 0, -1);
	if (keycode == 65364 || keycode == 115)
		player_action(game, 0, 1);
	if (keycode == 65361 || keycode == 97)
		player_action(game, -1, 0);
	if (keycode == 65363 || keycode == 100)
		player_action(game, 1, 0);
	return (0);
}
