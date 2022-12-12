/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:55:19 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/12 17:04:39 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_data(int keycode, __unused t_all *all)
{
	printf("%d\n", keycode);
	//mlx_destroy_window(all->mlx.mlx, all->mlx.window);
	//handle_error ("Window closed");
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int	win_mlx_loop(t_all *all)
{
	t_data	img;
	int		x;
	int		y;

	img.img = mlx_new_image(all->mlx.mlx, all->txtr.r_int[0], all->txtr.r_int[1]);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 20;
	while (y++ < 550)
	{
		x = 100 + (y / 2);
		while (x++ < 900 - (y / 2))
			my_mlx_pixel_put(&img, x, y, create_trgb(0, all->txtr.c_int[0],all->txtr.c_int[1],all->txtr.c_int[2]));
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.window, img.img, 0, 0);
	mlx_loop(all->mlx.mlx);
	return (0);
}