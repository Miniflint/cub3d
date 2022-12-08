/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:32:01 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/08 11:37:56 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_textures(t_all *all)
{
	if (all->txtr.no)
		free(all->txtr.no);
	if (all->txtr.so)
		free(all->txtr.so);
	if (all->txtr.we)
		free(all->txtr.we);
	if (all->txtr.ea)
		free(all->txtr.ea);
	if (all->txtr.f)
		free(all->txtr.f);
	if (all->txtr.c)
		free(all->txtr.c);
}

void	free_double_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_map(t_all *all)
{
	if (all->map.file)
		free(all->map.file);
	if (all->map.map_array)
		free(all->map.map_array);
	if (all->map.map)
		free_double_tab(all->map.map);
}

void	free_all(void)
{
	t_all	*all;

	all = ft_get_all(NULL);
	free_textures(all);
	free_map(all);
}
