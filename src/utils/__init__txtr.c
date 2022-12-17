/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__txtr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:37:39 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/17 17:28:29 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// initialise les textures C et F en tant que int plutot que char *
// avec 50k checks parce que j'ai eu des soucis aussi xDD
// je hais le C
// (c'est faux)
// ft_strlen_uc in src/utils/ft_strlen.c
// ft_occurence in src/utils/ft_strlen.c
// ft_atoi in src/utils/ft_atoi.c
static int	__init__res(t_all *all)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = all->txtr.r;
	while (++i < 2)
	{
		all->txtr.r_int[i] = ft_atoi(tmp);
		if (all->txtr.r_int[i] == -1)
			return (1);
		tmp += ft_strlen_uc(tmp, ' ') + 1;
		if (!tmp)
			return (1);
	}
	return (0);
}

static int	__util_txtr_init(t_all *all)
{
	int	i;
	char	*tmp[2];

	i = -1;
	tmp[0] = all->txtr.c;
	tmp[1] = all->txtr.f;
	while (++i < 3)
	{
		all->txtr.c_int[i] = ft_atoi(tmp[0]);
		all->txtr.f_int[i] = ft_atoi(tmp[1]);
		if (all->txtr.c_int[i] < 0 || all->txtr.f_int[i] < 0
			|| all->txtr.c_int[i] > 255 || all->txtr.f_int[i] > 255)
			return (1);
		tmp[0] += ft_strlen_uc(tmp[0], ',') + 1;
		tmp[1] += ft_strlen_uc(tmp[1], ',') + 1;
		if (!tmp[0] || !tmp[1])
			return (1);
	}
	if (__init__res(all))
		return (1);
	return (0);
}

// assigner toutes les bonnes valeurs au bons endroits
// cut_strstr_dup in src/parse/cut_strstr.c
// ft_strstr in src/utils/ft_strstr.c
// problem si les noms ont en majuscule: exemple ./textures/EAST.xpm *(ca va choper ST.xpm)*
// fix by checking if there's nothing before OR a \n (debut fichier / debut de ligne)
int	__init_textures(t_all *all)
{
	char	*map_file;

	map_file = all->map.file;
	all->txtr.no = cut_strstr_dup(ft_strstr(map_file, "NO "), '\n', 0, 2);
	all->txtr.so = cut_strstr_dup(ft_strstr(map_file, "SO "), '\n', 0, 2);
	all->txtr.we = cut_strstr_dup(ft_strstr(map_file, "WE "), '\n', 0, 2);
	all->txtr.ea = cut_strstr_dup(ft_strstr(map_file, "EA "), '\n', 0, 2);
	all->txtr.f = cut_strstr_dup(ft_strstr(map_file, "F "), '\n', 0, 1);
	all->txtr.c = cut_strstr_dup(ft_strstr(map_file, "C "), '\n', 0, 1);
	all->txtr.r = cut_strstr_dup(ft_strstr(map_file, "R "), '\n', 0, 1);
	if (!all->txtr.no || !all->txtr.so || !all->txtr.we || !all->txtr.ea
		|| !all->txtr.f || !all->txtr.c || !all->txtr.r)
		handle_error("Couldn't get textures");
	if (ft_occurence(all->txtr.c, ',') != 2
		|| ft_occurence(all->txtr.f, ',') != 2)
		handle_error("Problem parsing colors");
	if (__util_txtr_init(all))
		handle_error("Problem parsing colors");
	if (check_xpm_exist(all))
		handle_error("texture path is not possible");
	return (0);
}

t_data	*__init__image(t_all *all, int width, int height)
{
	t_data	*img;

	img = malloc(sizeof(t_data));
	if (!img)
		handle_error("Couldn't malloc image");
	img->img = mlx_new_image(all->mlx.mlx, width, height);
	if (!img->img)
		handle_error("Couldn't create image");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		handle_error("Couldn't get image address");
	return (img);
}