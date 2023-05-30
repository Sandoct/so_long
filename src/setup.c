/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:22:27 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/30 17:15:54 by gpouzet          ###   ########.fr       */
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
	return (0);
}

static int	set_texture_addr(t_game *game)
{
	if (set_addr(&game->texture.tile))
		return (1);
	if (set_addr(&game->texture.player))
	{
		mlx_destroy_image(game->mlx, game->texture.tile.img);
		return (1);
	}
	if (set_addr(&game->texture.collectible))
	{
		mlx_destroy_image(game->mlx, game->texture.tile.img);
		mlx_destroy_image(game->mlx, game->texture.player.img);
		return (1);
	}
	return (0);
}

int	set_texture(t_game *game)
{
	game->texture.tile.img = mlx_xpm_file_to_image(game->mlx, T_TILES, \
			&game->texture.tile.width, &game->texture.tile.height);
	if (game->texture.tile.img == NULL)
		return (1);
	game->texture.player.img = mlx_xpm_file_to_image(game->mlx, T_PLAYER, \
			&game->texture.player.width, &game->texture.player.height);
	if (game->texture.player.img == NULL)
	{
		mlx_destroy_image(game->mlx, game->texture.tile.img);
		return (1);
	}
	game->texture.collectible.img = mlx_xpm_file_to_image(game->mlx, \
			T_ITEM, &game->texture.collectible.width, \
			&game->texture.collectible.height);
	if (game->texture.collectible.img == NULL)
	{
		mlx_destroy_image(game->mlx, game->texture.tile.img);
		mlx_destroy_image(game->mlx, game->texture.player.img);
		return (1);
	}
	if (set_texture_addr(game))
		return (1);
	return (0);
}
