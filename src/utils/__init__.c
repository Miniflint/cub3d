/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:28:30 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/08 12:28:18 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
	TODO
	
	INIT MAP
*/

static int	__init_textures(t_all *all)
{
	int	i;
	char	*tmp1;
	char	*tmp2;

	all->txtr.no = cut_strstr_dup(ft_strstr(all->map.file, "NO") + 2, '\n');
	all->txtr.so = cut_strstr_dup(ft_strstr(all->map.file, "SO") + 2, '\n');
	all->txtr.we = cut_strstr_dup(ft_strstr(all->map.file, "WE") + 2, '\n');
	all->txtr.ea = cut_strstr_dup(ft_strstr(all->map.file, "EA") + 2, '\n');
	all->txtr.f = cut_strstr_dup(ft_strstr(all->map.file, "F") + 1, '\n');
	all->txtr.c = cut_strstr_dup(ft_strstr(all->map.file, "C") + 1, '\n');
	if (!all->txtr.no || !all->txtr.so || !all->txtr.we || !all->txtr.ea
		|| !all->txtr.f || !all->txtr.c)
		return (1);
	i = -1;
	tmp1 = all->txtr.c;
	tmp2 = all->txtr.f;
	while (++i < 3)
	{
		all->txtr.c_int[i] = ft_atoi(tmp1);
		all->txtr.f_int[i] = ft_atoi(tmp2);
		tmp1 = tmp1 + ft_strlen_uc(tmp1, ',') + 1;
		tmp2 = tmp2 + ft_strlen_uc(tmp2, ',') + 1;
	}
	return (0);
}

static int	__init_map(t_all *all)
{
	if (check_ext(all->path_to_map))
		handle_error("Wrong extension name");
	all->map.file = read_map(all->path_to_map);
	if (!all->map.file)
		handle_error("Couldn't reading the map");
	all->map.map_array = cut_strstr_dup(ft_strstr_map(all->map.file, "11"), '\0');
	if (!all->map.map_array)
		handle_error ("No map available");
	all->map.map = get_map(all);
	if (!all->map.map)
		handle_error("Error init double array");
	return (0);
}

static void	everything_null(t_all *all)
{
	all->txtr.f = NULL;
	all->txtr.c = NULL;
	all->txtr.no = NULL;
	all->txtr.so = NULL;
	all->txtr.we = NULL;
	all->txtr.ea = NULL;
	all->map.map = NULL;
	all->map.file = NULL;
	all->map.map_array = NULL;
	all->player.x = 0;
	all->player.y = 0;
}

int	__init__(t_all *all)
{
	everything_null(all);
	if (__init_map(all))
		return (1);
	if (__init_textures(all))
		handle_error("Couldn't init textures");
	return (0);
}
