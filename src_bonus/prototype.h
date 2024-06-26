/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:22:42 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/30 17:52:44 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H
# include "so_long.h"

void	scan_map(t_game *game);
/*		render.c		*/
void	render_map(t_game *game, char **map);
void	render_tiles(t_game game, int x, int y, char tile);
void	render_entity(t_game game, t_img *til, int x_map, int y_map);
void	render_number(t_game game, int x_map, int y_map, int number);
/*		setup.c			*/
int		destroy_texture(t_game *game, int level);
int		set_addr(t_img *img);
int		set_texture(t_game *game);
void	set_player(t_pc *player, int x, int y);
/*		tools.c			*/
void	move_on_screen(t_game *game, int move);
void	freetab(char **tab);
/*		map.c			*/
char	**map_format(char *file);
void	displayed_map(t_game *game, int x_border, int y_border);
/*		autre			*/
int		parser(char **map);
int		collectible(char **map);
t_pc	player_position_parser(char **map);
void	player_position(t_game *game);
int		get_pixel_color(t_data *data, int x, int y);
void	my_pixel_put(t_data *data, int x, int y, int color);
int		so_long(char *file);
int		hook_handler(int keycode, t_game *game);
int		sprite(t_game *game);
int		close_game(t_game *game);
#endif
