/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:33:27 by gpouzet           #+#    #+#             */
/*   Updated: 2023/05/11 13:05:37 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
//#include "libft/get_next_line.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd("Error\n", 2));
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".ber", 4))
		return (ft_putstr_fd("Error false extention for map\n", 2));
	so_long(argv[1]);
	return (0);
}
