/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:33:27 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/16 17:51:20 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
//#include "libft/get_next_line.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2)
		return (ft_putstr_fd("Error\n", 2));
	while (++i < argc)
		if (ft_strncmp((argv[i] + ft_strlen(argv[i]) - 4), ".ber", 4))
			return (ft_putstr_fd("Error false extention for map\n", 2));
	i = 0;
	while (++i < argc)
		if (so_long(argv[i]))
			return (1);
	return (0);
}
