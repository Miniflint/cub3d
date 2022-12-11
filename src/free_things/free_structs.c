/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:32:01 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 15:47:04 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_null(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;	
	}
}

void	free_textures(t_all *all)
{
	free_null(&all->txtr.no);
	free_null(&all->txtr.so);
	free_null(&all->txtr.we);
	free_null(&all->txtr.ea);
	free_null(&all->txtr.f);
	free_null(&all->txtr.c);
}

void	free_double_tab(char **str)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
			free_null(&str[i]);
	}
	free(str);
	str = NULL;
}

void	free_map(t_all *all)
{
	free_null(&all->map.file);
	free_null(&all->map.map_array);
	free_double_tab(all->map.map);
}

void	free_all(void)
{
	t_all	*all;

	all = ft_get_all(NULL);
	free_textures(all);
	free_map(all);
}
