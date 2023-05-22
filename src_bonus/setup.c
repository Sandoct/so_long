/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:22:27 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/20 20:02:59 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

void	set_player(t_pc *player, int x, int y)
{
	player->x = x;
	player->y = y;
	player->move = 0;
	player->collected = 0;
	player->footprint = '0';
}

static void	set_addr(t_img *img)
{
	img->data.addr = mlx_get_data_addr(img->img, &img->data.bits_per_pixel, \
			&img->data.line_length, &img->data.endian);
	img->direction = 1;
}

void	set_texture(t_game *game)
{
	game->texture.tile.img = mlx_xpm_file_to_image(game->mlx, T_TILES, \
			&game->texture.tile.width, &game->texture.tile.height);
	game->texture.npc.img = mlx_xpm_file_to_image(game->mlx, T_NPC, \
			&game->texture.npc.width, &game->texture.npc.height);
	game->texture.player.img = mlx_xpm_file_to_image(game->mlx, T_PLAYER, \
			&game->texture.player.width, &game->texture.player.height);
	game->texture.collectible.img = mlx_xpm_file_to_image(game->mlx, \
			T_ITEM, &game->texture.collectible.width, \
			&game->texture.collectible.height);
	game->texture.nb.img = mlx_xpm_file_to_image(game->mlx, H_NB, \
			&game->texture.nb.width, &game->texture.nb.height);
	set_addr(&game->texture.tile);
	set_addr(&game->texture.player);
	set_addr(&game->texture.npc);
	set_addr(&game->texture.collectible);
	set_addr(&game->texture.nb);
	game->texture.player.sprite = S_PLAYER;
	game->texture.collectible.sprite = S_ITEM;
	game->texture.npc.sprite = S_NPC;
}

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
