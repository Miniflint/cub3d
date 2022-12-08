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
	all->txtr.no = cut_strstr_dup(ft_strstr(all->map.file, "NO"), '\n');
	all->txtr.so = cut_strstr_dup(ft_strstr(all->map.file, "SO"), '\n');
	all->txtr.we = cut_strstr_dup(ft_strstr(all->map.file, "WE"), '\n');
	all->txtr.ea = cut_strstr_dup(ft_strstr(all->map.file, "EA"), '\n');
	all->txtr.f = cut_strstr_dup(ft_strstr(all->map.file, "F"), '\n');
	all->txtr.c = cut_strstr_dup(ft_strstr(all->map.file, "C"), '\n');
	if (!all->txtr.no || !all->txtr.so || !all->txtr.we || !all->txtr.ea
		|| !all->txtr.f || !all->txtr.c)
		return (1);
	return (0);
}

static int	__init_map(t_all *all)
{
	if (check_ext(all->path_to_map))
		handle_error("Wrong extension name");
	all->map.file = read_map(all->path_to_map);
	if (!all->map.file)
		handle_error("Couldn't reading the map");
	if (__init_textures(all))
		handle_error("Couldn't init textures");
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
	return (0);
}