/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:22:27 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/30 18:07:17 by gpouzet          ###   ########.fr       */
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

int	set_addr(t_img *img)
{
	img->data.addr = mlx_get_data_addr(img->img, &img->data.bits_per_pixel, \
			&img->data.line_length, &img->data.endian);
	if (img->data.addr == NULL)
		return (1);
	img->direction = 1;
	return (0);
}

int	destroy_texture(t_game *game, int level)
{
	if (level > 0)
		mlx_destroy_image(game->mlx, game->texture.tile.img);
	if (level > 1)
		mlx_destroy_image(game->mlx, game->texture.player.img);
	if (level > 2)
		mlx_destroy_image(game->mlx, game->texture.collectible.img);
	if (level > 3)
		mlx_destroy_image(game->mlx, game->texture.npc.img);
	if (level > 4)
		mlx_destroy_image(game->mlx, game->texture.nb.img);
	return (1);
}

static int	set_texture_addr(t_game *game)
{
	if (set_addr(&game->texture.tile))
		return (destroy_texture(game, 1));
	if (set_addr(&game->texture.player))
		return (destroy_texture(game, 2));
	if (set_addr(&game->texture.collectible))
		return (destroy_texture(game, 3));
	if (set_addr(&game->texture.npc))
		return (destroy_texture(game, 4));
	if (set_addr(&game->texture.nb))
		return (destroy_texture(game, 5));
	game->texture.player.sprite = S_PLAYER;
	game->texture.collectible.sprite = S_ITEM;
	game->texture.npc.sprite = S_NPC;
	return (0);
}

int	set_texture(t_game *game)
{
	game->texture.tile.img = mlx_xpm_file_to_image(game->mlx, T_TILES, \
			&game->texture.tile.width, &game->texture.tile.height);
	if (game->texture.tile.img == NULL)
		return (destroy_texture(game, 0));
	game->texture.player.img = mlx_xpm_file_to_image(game->mlx, T_PLAYER, \
			&game->texture.player.width, &game->texture.player.height);
	if (game->texture.player.img == NULL)
		return (destroy_texture(game, 1));
	game->texture.collectible.img = mlx_xpm_file_to_image(game->mlx, \
			T_ITEM, &game->texture.collectible.width, \
			&game->texture.collectible.height);
	if (game->texture.collectible.img == NULL)
		return (destroy_texture(game, 2));
	game->texture.npc.img = mlx_xpm_file_to_image(game->mlx, T_NPC, \
			&game->texture.npc.width, &game->texture.npc.height);
	if (game->texture.npc.img == NULL)
		return (destroy_texture(game, 3));
	game->texture.nb.img = mlx_xpm_file_to_image(game->mlx, H_NB, \
			&game->texture.nb.width, &game->texture.nb.height);
	if (game->texture.nb.img == NULL)
		return (destroy_texture(game, 4));
	return (set_texture_addr(game));
}
