/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:34:22 by gpouzet           #+#    #+#             */
/*   Updated: 2023/04/29 19:55:45 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf.h"
#include "../minilibx/mlx.h"
#include "../minilibx/mlx_int.h"


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data data, int x, int y, int color, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i - x < size)
		my_mlx_pixel_put(&data, i++ + x, y, color);
	while (j - y < size)
		my_mlx_pixel_put(&data, x, j++ + y, color);
}

int	close_window(int keycode, t_vars *vars)
{
	ft_printf("keycode : %d.\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
//	t_data	img;
	void	*img2;
	int		img_width;
	int		img_height;
	void	*img3;
	int		img3_width;
	int		img3_height;

	img_width = 0;
	img_height = 0;
	img3_width = 0;
	img3_height = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img2 = mlx_xpm_file_to_image(vars.mlx, "textures/mandatory/game/tiles.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(vars.mlx, "textures/mandatory/game/player.xpm", &img3_width, &img3_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img2, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img3, 15, 15);
//	img.img = mlx_new_image(vars.mlx, 960, 540);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	draw_square(img, 5, 5, 0x00FF0000, 200);
//	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
//	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
}
