/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:28:30 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/13 15:33:14 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static double	get_angle(char c)
{
	if (c == 'N')
		return (0);
	if (c == 'W')
		return (90);
	if (c == 'S')
		return (180);
	if (c == 'E')
		return (270);
	return (-1);
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
	all->player.x = all->player.start_x;
	all->player.y = all->player.start_y;
	all->player.angle = get_angle(all->player.letter);
	if (all->player.angle == -1)
		return (1);
	printf("%f\n", all->player.angle);
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

static int	__init_mlx(t_all *all)
{
	all->mlx.mlx = mlx_init();
	if (!all->mlx.mlx)
		return (1);
	all->mlx.window = mlx_new_window(all->mlx.mlx, all->txtr.r_int[0], all->txtr.r_int[1] + 2, "COUCOU");
	if (!all->mlx.window)
		return (1);
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
	if (__init_mlx(all))
		return (1);
	return (0);
}
