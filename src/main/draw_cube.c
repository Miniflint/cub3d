/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:41:56 by sbars             #+#    #+#             */
/*   Updated: 2022/12/19 17:33:07 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
** 1. Create a new image with the size of the window 
** 2. Draw a column of the texture on the image for each pixel of the window width
** 3. Return the image with the texture drawn on it 
*/


// unsigned int	get_pixel(t_texture tex, int x, int y)
// {
// 	char	*dst;

// 	dst = tex.img.addr + (y * tex.img.linelen + x * (tex.img.bpp / 8));
// 	return (*(unsigned int *)dst);
// }

t_data  *draw_cube(t_all   *all)
{
    t_data  *img;
    int     x;
    int     cube_height;

    img = __img_init(all->mlx.mlx, all->txtr.r_int[0] / 2, all->txtr.r_int[1] / 2);
    if (!img)
    {
        printf("Error\n");
        return (NULL);
    }
    x = 0;
    cube_height = 500;
    while (x < (all->txtr.r_int[0] / 2) - 2)
    {
        printf("salut\n");
        // if (cube_height < 10)
        //     cube_height++;
        // else if (cube_height >= 10)
        //     cube_height--;
        // draw_column_texture(all->mlx.image, x, cube_height);
        my_mlx_pixel_put(img, x, 200, get_col_text_pixel(all->txtr.ea_img, x, 0));
        x++;
    }
    mlx_put_image_to_window(all->mlx.mlx, all->mlx.window, img->img, 400, 400);
    //mlx_put_image_to_window(all->mlx.mlx, all->mlx.window, all->txtr.no_img->img, 200, 200);
    return (NULL);
}

int get_col_text_pixel(t_data *img, int x, int y)
{
    char    *dst;

    dst = img->addr + y + (x * (img->bits_per_pixel / 8));
    return (*(unsigned int *)dst);
}

int scale_step(int i, int cube_height, int y)
{
    return (i * y / cube_height);
    // hauteur de la colonne de pixels / scale que je veux
    
}

int project_x(int x)
{
    return (x);
}

void    draw_column_texture(t_data *img, int x, int cube_height)
{
    int     tex_y;
    int     color;
    int     i;
    t_all   *all;

    all = ft_get_all(NULL);
    tex_y = (all->txtr.r_int[1] - cube_height) / 2;
    i = 0;
    while (i < cube_height)
    {
        tex_y = scale_step(i, cube_height, all->txtr.r_int[1]);
        color = get_col_text_pixel(img, project_x(x), tex_y);
        if (color != 0)
            my_mlx_pixel_put(img, x, tex_y, color);
        i++;
    }
}