/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:22:42 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/22 15:40:15 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H
# include "so_long.h"

/*		render.c	*/
void	render_map(t_game *game);
void	render_tiles(t_game game, int x, int y, char tile);
void	render_entity(t_game game, t_img til, int x_map, int y_map);
/*		setup.c		*/
void	set_player(t_pc *player, int x, int y);
void	set_texture(t_game *game);
void	set_addr(t_img *img);
/*		tools.c		*/
void	freetab(char **tab);
int		collectible(char **map);
t_pc	player_position(char **map);
int		get_pixel_color(t_data *data, int x, int y);
void	my_pixel_put(t_data *data, int x, int y, int color);
/*		event.c		*/
int		hook_handler(int keycode, t_game *game);
int		close_game(t_game *game);
/*		autre		*/
char	**map_format(char *file);
int		parser(char **map);
int		so_long(char *file);
#endif
