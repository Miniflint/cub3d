#include "../../inc/cub3d.h"

#define PX 64

void    big_pixel(t_data *img, int size, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            my_mlx_pixel_put(img, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void    draw_map(t_all *all)
{
    char    **map;
    int x;
    int y;
    int size;
    t_data  img;

    y = -1;
	all->mlx.image = &img;
    map = all->map.map;
	img.img = mlx_new_image(all->mlx.mlx, all->txtr.r_int[0] / 2, all->txtr.r_int[1] / 2);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (map[++y])
    {
        x = -1;
        while (map[y][++x])
        {
            size = 0;
            if (map[y][x] == '1')
                big_pixel(&img, PX, (x * PX) + 10, (y * PX) + 10, 0xB4D455);
            else
                big_pixel(&img, PX, (x * PX) + 10, (y * PX) + 10, 0x0000FF);
            big_pixel(&img, 12, (all->player.x * PX) + 10, (all->player.y * PX) + 10, 0xABCDEF);
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.window, img.img, 10, 10);
}