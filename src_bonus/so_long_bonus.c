/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:53:01 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/22 16:16:23 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

static int	mlx_start(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	game->win = mlx_new_window(game->mlx, \
			S_WIDTH * 64, S_HEIGHT * 64, "so_long");
	game->frame.img = mlx_new_image(game->mlx, S_WIDTH * 64, S_HEIGHT * 64);
	game->frame.data.addr = mlx_get_data_addr(game->frame.img, \
			&game->frame.data.bits_per_pixel, &game->frame.data.line_length, \
			&game->frame.data.endian);
	set_texture(game);
	return (0);
}

static void	mlx_end(t_game *game)
{
	mlx_destroy_image(game->mlx, game->frame.img);
	mlx_destroy_image(game->mlx, game->texture.tile.img);
	mlx_destroy_image(game->mlx, game->texture.player.img);
	mlx_destroy_image(game->mlx, game->texture.collectible.img);
	mlx_destroy_image(game->mlx, game->texture.npc.img);
	mlx_destroy_image(game->mlx, game->texture.nb.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	so_long(char *file)
{
	t_game	game;

	if (mlx_start(&game))
		return (1);
	game.map = map_format(file);
	if (game.map == NULL)
		return (1);
	game.map_width = ft_strlen(*game.map);
	game.map_height = ft_tabstrlen(game.map);
	scan_map(&game);
	displayed_map(&game, 7, 3);
	player_position(&game);
	render_map(&game, game.map_disp);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, hook_handler, &game);
	mlx_loop_hook(game.mlx, sprite, &game);
	mlx_loop(game.mlx);
	freetab(game.map_disp);
	freetab(game.map);
	mlx_end(&game);
	return (0);
}
