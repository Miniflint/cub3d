#include "../../inc/cub3d.h"

void    big_pixel(t_data *img, int size, int y, int x, int color)
{
	int	i;
	int	j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            my_mlx_pixel_put(img, x + i, y + j, color);
            if (j == size - 1 || i == size - 1)
                my_mlx_pixel_put(img, x + i, y + j, 0x00000);
            j++;
        }
        i++;
    }
}

void	draw_map(t_all *all)
{
    char    **map;
    int x;
    int y;
    t_data  img;
	double	hit_vert;
	double	hit_hor;
	
	hit_vert = cal_hyp(all->player.y, all->player.x, all->player.raycast.v.y, all->player.raycast.v.x);
	hit_hor = cal_hyp(all->player.y, all->player.x, all->player.raycast.h.y, all->player.raycast.h.x);
	printf("hit vertical: %f - hit horizontal: %f\n", hit_vert, hit_hor);

	y = -1;
	all->mlx.image = &img;
	map = all->map.map;
	img.img = mlx_new_image(all->mlx.mlx, 256, 256);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (map[++y])
    {
        x = -1;
        while (map[y][++x])
        {
            if (map[y][x] == '1')
                big_pixel(&img, PX, (y * PX), (x * PX), 0x00FF00);
            else
                big_pixel(&img, PX, (y * PX), (x * PX), 0x0000FF);
            big_pixel(&img, PX / 4, (all->player.y * PX), (all->player.x * PX), 0xFF0000);
        }
    }
    // big_pixel(&img, PX / 4, (all->player.raycast.v.y) * PX, (all->player.raycast.v.x) * PX, 0xFFFFFF);
    // big_pixel(&img, PX / 4, (all->player.raycast.v.y) * PX, (all->player.raycast.v.x) * PX, 0xFFFFFF);
	if (hit_vert < hit_hor)
        big_pixel(&img, PX / 4, (all->player.raycast.v.my) * PX, (all->player.raycast.v.x) * PX, 0xFFFFFF);
	else
        big_pixel(&img, PX / 4, (all->player.raycast.h.y) * PX, (all->player.raycast.h.mx) * PX, 0x000000);
    //big_pixel(&img, PX / 4, (all->player.raycast2.y) * PX, (all->player.raycast2.x) * PX, 0xBBBBBB);
    //big_pixel(&img, PX / 4, (all->player.raycast.v.y) * PX, (all->player.raycast.v.x) * PX, 0xBBBBBB);
    //big_pixel(&img, PX / 4, (all->player.raycast.h.y) * PX, (all->player.raycast.h.x) * PX, 0xB4D455);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.window, img.img, 10, 10);
}
