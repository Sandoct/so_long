/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:22:27 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/22 15:37:34 by gpouzet          ###   ########.fr       */
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

void	set_addr(t_img *img)
{
	img->data.addr = mlx_get_data_addr(img->img, &img->data.bits_per_pixel, \
			&img->data.line_length, &img->data.endian);
}

void	set_texture(t_game *game)
{
	game->texture.tile.img = mlx_xpm_file_to_image(game->mlx, T_TILES, \
			&game->texture.tile.width, &game->texture.tile.height);
	game->texture.player.img = mlx_xpm_file_to_image(game->mlx, T_PLAYER, \
			&game->texture.player.width, &game->texture.player.height);
	game->texture.collectible.img = mlx_xpm_file_to_image(game->mlx, \
			T_ITEM, &game->texture.collectible.width, \
			&game->texture.collectible.height);
	set_addr(&game->texture.tile);
	set_addr(&game->texture.player);
	set_addr(&game->texture.collectible);
}
