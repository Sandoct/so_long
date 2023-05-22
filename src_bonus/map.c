/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:27:13 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/22 16:13:10 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../minilibx/mlx.h"
#include "fcntl.h"
#include "so_long.h"

static char	*all_file_in_line(int fd)
{
	char	*readed;
	char	*read;

	read = get_next_line(fd);
	if (read == NULL)
		return (NULL);
	readed = ft_calloc(1, 1);
	if (readed == NULL)
	{
		free(read);
		return (NULL);
	}
	while (read != NULL)
	{
		readed = ft_strmerge(readed, read);
		if (readed == NULL)
			return (NULL);
		read = get_next_line(fd);
	}
	return (readed);
}

char	**map_format(char *file)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		ft_putstr_fd("map file incorect\n", 1);
		return (NULL);
	}
	line = all_file_in_line(fd);
	close(fd);
	map = ft_split(line, '\n');
	if (parser(map))
	{
		freetab(map);
		free(line);
		return (NULL);
	}
	freetab(map);
	map = ft_split(line, '\n');
	free(line);
	if (map == NULL)
		ft_putstr_fd("Error malloc failled\n", 2);
	return (map);
}

void	displayed_map(t_game *game, int x_border, int y_border)
{
	int	x;
	int	y;

	y = -1;
	game->map_disp = ft_calloc(S_HEIGHT + 1, sizeof(char *));
	while (++y < S_HEIGHT)
		game->map_disp[y] = ft_calloc(S_WIDTH + 1, sizeof(char));
	y = -1;
	while (++y < S_HEIGHT)
	{
		x = -1;
		while (++x < S_WIDTH)
		{
			if (game->player.y - y_border + y < 0
				|| game->player.x - x_border + x < 0)
				game->map_disp[y][x] = '2';
			else if (game->player.y - y_border + y >= (int)game->map_height
				|| game->player.x - x_border + x >= (int)game->map_width)
				game->map_disp[y][x] = '2';
			else
				game->map_disp[y][x] = game->map[game->player.y - y_border + y] \
												[game->player.x - x_border + x];
		}
	}
}

void	move_on_screen(t_game *game, int move)
{
	char	*numbers;
	char	*number;
	int		i;

	i = 0;
	numbers = ft_itoa(move);
	render_map(game, game->map_disp);
	while (numbers[i])
	{
		number = ft_substr(numbers, i, 1);
		render_tiles(*game, i, 0, game->map_disp[0][i]);
		if (game->map_disp[0][i] == 'C')
			render_entity(*game, &game->texture.collectible, i * 64, 0);
		if (game->map_disp[0][i] == 'N')
			render_entity(*game, &game->texture.npc, i * 64, 0);
		render_number(*game, ++i * 32, 16, ft_atoi(number));
		free(number);
	}
	free(numbers);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}
