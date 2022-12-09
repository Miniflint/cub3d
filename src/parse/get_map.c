/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:50:02 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/09 13:50:03 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	**get_map(t_all *all)
{
	char	**map;
	char	*tmp;
	int		i;
	int		len_line;
	const int	height_map
		= check_map_height(all->map.map_array);

	map = malloc(sizeof(char *) * (height_map + 1));
	if (!map)
		return (NULL);
	i = -1;
	tmp = all->map.map_array;
	while (++i < height_map)
	{
		len_line = ft_strlen_uc(tmp, '\n');
		map[i] = ft_strldup(tmp, len_line);
		while (len_line--)
			tmp++;
		tmp++;
	}
	map[i] = NULL;
	return (map);
}
