/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:33:27 by gpouzet           #+#    #+#             */
/*   Updated: 2023/04/29 19:54:26 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
//#include "libft/get_next_line.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

void showmap(char *file)
{
	char	**map;
	int		i;

	i = 0;
	map = map_format(file);
	if (map == NULL)
		return ;
	while (map[i])
	{
		ft_putstr_fd(map[i++], 1);
		ft_putstr_fd("\n", 1);
	}
	freetab(map);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd("Error\n", 2));
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".ber", 4))
		return (ft_putstr_fd("Error false extention for map\n", 2));
	showmap(argv[1]);
	return (0);
}
