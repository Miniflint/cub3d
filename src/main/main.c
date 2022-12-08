/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:27:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/08 12:34:42 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	test(void)
{
	t_all	*all;
	int	i;

	i = -1;
	all = ft_get_all(NULL);
	printf("%s\n%s\n%s\n", all->txtr.no, all->txtr.so, all->txtr.we);
	printf("%s\n%s\n%s\n", all->txtr.ea, all->txtr.f, all->txtr.c);
	while (all->map.map[++i])
		printf("map[%i]: %s\n", i, all->map.map[i]);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		return (1);
	ft_get_all(&all);
	all.path_to_map = argv[1];
	__init__(&all);
	test();
	free_all();
	return (0);
}
