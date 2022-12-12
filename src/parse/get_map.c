/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:50:02 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 18:44:32 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


//fonction faite pour copier un double tableau
// ft_strdup in src//utils/ft_strdup.c
char	**cp_map(char **map, int height_map)
{
	int		i;
	char	**new_map;
	
	new_map = malloc(sizeof(char *) * (height_map + 2));
	if (!new_map)
		return (NULL);
	i = -1;
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	new_map[i] = NULL;
	return (new_map);
}

// parsage de map depuis le fichier
// et renvoie un double tableau malloqué
// voir ft_strlen_uc dans src/utils/ft_strlen.c
// et ft_strldup dans src/utils/ft_strdup.c
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
	all->map.map_height = height_map;
	i = -1;
	tmp = all->map.map_array;
	while (++i < height_map)
	{
		len_line = ft_strlen_uc(tmp, '\n');
		map[i] = ft_strldup(tmp, len_line);
		while (len_line-- >= 0)
			tmp++;
	}
	map[i] = NULL;
	return (map);
}
