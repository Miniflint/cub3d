/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:55:19 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/17 18:36:51 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	close_window(void)
{
	t_all	*all;

	all = ft_get_all(NULL);
	free_all();
	if (!mlx_clear_window(all->mlx.mlx, all->mlx.window))
		return (1);
	mlx_destroy_window(all->mlx.mlx, all->mlx.window);
	printf("Closing the window !\n");
	exit (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | b << 8 | g);
}

static void	loop_hooks(t_all *all)
{
	// to destroy window
	// mlx_hook(all->mlx.window, ON_MOUSEMOVE, 0, )
	mlx_hook(all->mlx.window, ON_KEYDOWN, 0, keyDowned, all);
	mlx_hook(all->mlx.window, ON_KEYUP, 0, keyUpped, all);
	mlx_hook(all->mlx.window, ON_DESTROY, 0, close_window, NULL);
}

void	assign_textures(t_all *all)
{
	char 	*tmp;
	int		x;
	int		y;
	t_data	t;

	x = 10;
	y = 10;
	tmp = ft_strdup(all->txtr.ea);
	t.img = mlx_xpm_file_to_image(all->mlx.mlx, tmp, &x, &y);
    t.addr = mlx_get_data_addr(t.img, &t.bits_per_pixel, &t.line_length, &t.endian);
	//mlx_put_image_to_window(all->mlx.mlx, all->mlx.window, t.img, x, y);
	free(tmp);
}

int	win_mlx_loop(t_all *all)
{
	t_data	img;
	int		x;
	int		y;

	all->mlx.image = &img;
	img.img = mlx_new_image(all->mlx.mlx, all->txtr.r_int[0], all->txtr.r_int[1]);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while (y++ < all->txtr.r_int[1] - 2)
	{
		x = 0;
		while (x++ < all->txtr.r_int[0])
			if (y > all->txtr.r_int[1] / 2)
				my_mlx_pixel_put(&img, x, y, create_trgb(0, all->txtr.c_int[0],all->txtr.c_int[1],all->txtr.c_int[2]));
			else
				my_mlx_pixel_put(&img, x, y, create_trgb(0, all->txtr.f_int[0],all->txtr.f_int[1],all->txtr.f_int[2]));
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.window, img.img, 0, 0);
	assign_textures(all);
	draw_map(all);
	loop_hooks(all);
	mlx_loop(all->mlx.mlx);
	mlx_destroy_image(all->mlx.mlx, img.img);
	return (0);
}
