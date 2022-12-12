/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:28:30 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/12 13:16:06 by tgoel            ###   ########.fr       */
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
static int	__util_txtr_init(t_all *all)
{
	int	i;
	char	*tmp[3];

	i = -1;
	tmp[0] = all->txtr.c;
	tmp[1] = all->txtr.f;
	tmp[2] = all->txtr.r;
	while (++i < 3)
	{
		all->txtr.c_int[i] = ft_atoi(tmp[0]);
		all->txtr.f_int[i] = ft_atoi(tmp[1]);
		if (i < 3)
			all->txtr.r_int[i] = ft_atoi(tmp[2]);
		if (all->txtr.c_int[i] < 0 || all->txtr.f_int[i] < 0
			|| all->txtr.c_int[i] > 255 || all->txtr.f_int[i] > 255)
			return (1);
		tmp[0] += ft_strlen_uc(tmp[0], ',') + 1;
		tmp[1] += ft_strlen_uc(tmp[1], ',') + 1;
		if (i < 3)
			tmp[2] += ft_strlen_uc(tmp[2], ' ') + 1;
		if (!tmp[0] || !tmp[1] || (i < 3 && !tmp[2]))
			return (1);
	}
	return (0);
}

// assigner toutes les bonnes valeurs au bons endroits
// cut_strstr_dup in src/parse/cut_strstr.c
// ft_strstr in src/utils/ft_strstr.c
static int	__init_textures(t_all *all)
{
	char	*map_file;

	map_file = all->map.file;
	all->txtr.no = cut_strstr_dup(ft_strstr(map_file, "NO"), '\n', 0, 2);
	all->txtr.so = cut_strstr_dup(ft_strstr(map_file, "SO"), '\n', 0, 2);
	all->txtr.we = cut_strstr_dup(ft_strstr(map_file, "WE"), '\n', 0, 2);
	all->txtr.ea = cut_strstr_dup(ft_strstr(map_file, "EA"), '\n', 0, 2);
	all->txtr.f = cut_strstr_dup(ft_strstr(map_file, "F"), '\n', 0, 1);
	all->txtr.c = cut_strstr_dup(ft_strstr(map_file, "C"), '\n', 0, 1);
	all->txtr.r = cut_strstr_dup(ft_strstr(map_file, "R"), '\n', 0, 1);
	if (!all->txtr.no || !all->txtr.so || !all->txtr.we || !all->txtr.ea
		|| !all->txtr.f || !all->txtr.c || !all->txtr.r)
		handle_error("Couldn't get textures");
	if (ft_occurence(all->txtr.c, ',') != 2
		|| ft_occurence(all->txtr.f, ',') != 2)
		handle_error("Problem parsing colors");
	if (__util_txtr_init(all))
		handle_error("Problem parsing colors");
	return (0);
}

// attribue la lettre au joueur et lui donne sa position
// check_nb_player in src/parse/check_map_error.c
// check_player_letter in src/parse/check_utils.c
// letter_pos_on_map in src/parse/check_utils.c
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
	return (0);
}

// check l'extension du fichier
// lis la map est la stock dans all->map.file
// essaie de parser la map si il la trouve (ça trouve à 100% quand la map est bien
// j'ai jamais testé avec des map entièrement conne ngl
// ft_strstr_map in src/utils/ft_strstr.c
// contains_fill in src/parse/check_map_errors.c
// get_map in src/parse/get_map.c
static int	__init_map(t_all *all)
{
	if (check_ext(all->path_to_map))
		handle_error("Wrong extension name");
	all->map.file = read_map(all->path_to_map);
	if (!all->map.file)
		handle_error("Couldn't reading the map");
	all->map.map_array = cut_strstr_dup(ft_strstr_map(all->map.file, "11"), '\0', 1, 0);
	if (!all->map.map_array)
		handle_error("No map available");
	if (contains_fill(all->map.map_array))
		handle_error("Illegal char in map");
	all->map.map = get_map(all);
	if (!all->map.map)
		handle_error("Error init double array");
	return (0);
}

// lance tout les initialisations
// voir __init_map
// voir __init_textures
// voir __init_player
int	__init__(t_all *all)
{
	everything_null(all);
	if (__init_map(all))
		return (1);
	if(__init_textures(all))
		return (1);
	if(__init_player(all))
		return (1);
	return (0);
}
