/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:28:30 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 18:50:52 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
	TODO
	
	INIT MAP
*/

static int	__util_txtr_init(t_all *all)
{
	int	i;
	char	*tmp[2];

	i = -1;
	tmp[0] = all->txtr.c;
	tmp[1] = all->txtr.f;
	if (ft_occurence(all->txtr.f, ',') != 2 || ft_occurence(all->txtr.c, ',') != 2)
		return (1);
	while (++i < 3)
	{
		all->txtr.c_int[i] = ft_atoi(tmp[0]);
		all->txtr.f_int[i] = ft_atoi(tmp[1]);
		if (all->txtr.c_int[i] < 0 || all->txtr.f_int[i] < 0)
			return (1);
		if (all->txtr.c_int[i] > 255 || all->txtr.f_int[i] > 255)
			return (1);
		tmp[0] += ft_strlen_uc(tmp[0], ',') + 1;
		tmp[1] += ft_strlen_uc(tmp[1], ',') + 1;
	}
	return (0);
}

static int	__init_textures(t_all *all)
{
	all->txtr.no = cut_strstr_dup(ft_strstr(all->map.file, "NO") + 2, '\n', 0);
	all->txtr.so = cut_strstr_dup(ft_strstr(all->map.file, "SO") + 2, '\n', 0);
	all->txtr.we = cut_strstr_dup(ft_strstr(all->map.file, "WE") + 2, '\n', 0);
	all->txtr.ea = cut_strstr_dup(ft_strstr(all->map.file, "EA") + 2, '\n', 0);
	all->txtr.f = cut_strstr_dup(ft_strstr(all->map.file, "F") + 1, '\n', 0);
	all->txtr.c = cut_strstr_dup(ft_strstr(all->map.file, "C") + 1, '\n', 0);
	if (!all->txtr.no || !all->txtr.so || !all->txtr.we || !all->txtr.ea
		|| !all->txtr.f || !all->txtr.c)
		handle_error("Couldn't get textures");
	if (__util_txtr_init(all))
		handle_error("Problem getting colors");
	return (0);
}

static int	__init_player(t_all *all)
{
	int	pos[2];

	if (check_nb_player(all->map.map_array))
		handle_error("Too much / not enough player on the map");
	all->player.letter = check_player_letter(all->map.map_array);
	if (!all->player.letter)
		handle_error("Couldn't find the player on the map");
	letter_pos_on_map(all->map.map, all->player.letter, pos);
	if (pos[0] == -1 || pos[1] == -1)
		handle_error("Couldn't find the player on the map");
	all->player.start_y = pos[0];
	all->player.start_x = pos[1];
	letter_pos_on_map(all->map.map, 'E', pos);
	return (0);
}

static int	__init_map(t_all *all)
{
	if (check_ext(all->path_to_map))
		handle_error("Wrong extension name");
	all->map.file = read_map(all->path_to_map);
	if (!all->map.file)
		handle_error("Couldn't reading the map");
	all->map.map_array = cut_strstr_dup(ft_strstr_map(all->map.file, "11"), '\0', 1);
	if (!all->map.map_array)
		handle_error("No map available");
	all->map.map = get_map(all);
	if (!all->map.map)
		handle_error("Error init double array");
	return (0);
}

int	__init__(t_all *all)
{
	everything_null(all);
	if (__init_map(all))
		return (1);
	if(__init_player(all))
		return (1);
	if(__init_textures(all))
		return (1);
	check_view_player(all);
	return (0);
}
