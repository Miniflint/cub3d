/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:27:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/09 13:46:30 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// juste pour tester les valeure prise dans la récupération du fichier
// rien de bien intéréssant ici
void	test(void)
{
	t_all	*all;
	int	i;
	
	all = ft_get_all(NULL);
	printf("Textures: \n");
	printf("\t%s\n\t%s\n\t%s\n\t%s\n", all->txtr.no, all->txtr.so,
			all->txtr.we, all->txtr.ea);
	printf("\n(Char) F and C\n");
	printf("\t%s\n\t%s\n", all->txtr.f, all->txtr.c);
	i = -1;
	printf("\n(Int) F and C\n");
	printf("\t%i,%i,%i\n", all->txtr.f_int[0], all->txtr.f_int[1],
			all->txtr.f_int[2]);
	printf("\t%i,%i,%i\n\n", all->txtr.c_int[0], all->txtr.c_int[1],
			all->txtr.c_int[2]);
	while (all->map.map[++i])
		printf("map[%i]: %s\n", i, all->map.map[i]);
}

// main programme
// crée une struct all et la met dans une fonction pour pouvoir la reprendre partout
// assigne le path_to_map
// initialize le parsing et tout ce qu'il faut
// lance le main checker pour la map et pour voir si ce'st accessible
// free quand c'est fini
// __init__ in __src/utils/__init__.c
// check_view_player in src/parse/check_map_errors.c
int	main(int argc, char **argv)
{
	t_all	all;

	if (argc < 2)
		return (1);
	ft_get_all(&all);
	all.path_to_map = argv[1];
	if (__init__(&all))
		return (1);
///	test();
	check_view_player(&all);
	free_all();
	return (0);
}
