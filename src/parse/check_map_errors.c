/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:33:22 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/13 16:49:34 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


// crée une copie de la map en allouant tout un nouveau double tableau
// modifie ce nouveau tableau à l'aide de la fonction check_path_player()
// print le tableau (on s'en fout de celui la)
// si la fonction check_map_open r'envoie quelque chose, ça veut dire que
// le joueur a théoriquement accès à en dehors de la map
// (mauvais signe)
// ducoup on free le double tableau pour éviter les leaks et on exit le programme
// sinon on return que la fonction c'est bien passée 
// cp_map in src/parse/get_map.c
// check_path_player in src/parse/check_utils.c
// check_map_open in src/parse/check_map_valid.c
int	check_view_player(t_all *all)
{
	char	**new_map;

	new_map = cp_map(all->map.map, all->map.map_height);
	if (!new_map)
		return (1);
	check_path_player(new_map, all->player.start_y,
		all->player.start_x, all->player.letter);
	//print_double_tab(new_map);
	if (check_map_open(new_map))
	{
		free_double_tab(new_map);
		handle_error("Map wrongly formatted");
	}
	free_double_tab(new_map);
	return (0);
}


// fonction pour checker si il y a plus de 1 joueur
// i = -1
// donc si il y a un joueur ça envoie à 0
// si la fonction r'envoie quelque chose autre que 0, il y a plus que 1 joueur sur la map
// ft_occurence in src/utils/ft_strlen.c
int	check_nb_player(char *str)
{
	int	i;

	i = -1;
	i += ft_occurence(str, 'N');
	i += ft_occurence(str, 'S');
	i += ft_occurence(str, 'W');
	i += ft_occurence(str, 'E');
	return (i);
}

// check if the map already contains the FILL '-' character
// if yes return 1
int	contains_fill(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == FILL)
			return (1);
	return (0);
}

// checker l'extension du nom de fichier pris
// maps/blabla.cub (très important, c'est noté dans le sujet qu'il
// faut pas prendre autre chose que .cub
// ft_strstr in src/utils/ft_strstr.c
int	check_ext(char *path)
{
	const int	len_path
		= ft_strlen(path);

	if (len_path <= 4)
		return (1);
	if (!ft_strstr(path + (len_path - 4), ".cub"))
		return (1);
	return (0);
}
