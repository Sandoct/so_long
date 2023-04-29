/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:27:13 by gpouzet           #+#    #+#             */
/*   Updated: 2023/04/29 19:55:20 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../minilibx/mlx.h"
#include "fcntl.h"
#include "so_long.h"

static char *all_file_in_line(int fd)
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
	int 	fd;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
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
/*
t_til	til_setup(mlx)
{
	t_til	til;

	til.wall.image = mlx_xpm_file_to_image(vars.mlx,
			"textures/mandatory/game/tiles.xpm", til.wall.height, til.wall.lenth);
	til.player;
	til.exit;
	til.start;
	til.loot;
	til.floor;
	return (til);
}

void	til_clear(t_til til)
{
	mlx_destroy_image(til.wall);
	mlx_destroy_image(til.player);
	mlx_destroy_image(til.exit);
	mlx_destroy_image(til.start);
	mlx_destroy_image(til.loot);
	mlx_destroy_image(til.floor);
}*/
