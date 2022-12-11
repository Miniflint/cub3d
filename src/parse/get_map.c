/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:50:02 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 18:21:58 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_letter_pos(char *str, char letter)
{
	t_all	*all;
	int	i;

	all = ft_get_all(NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == letter)
		{
			all->player.start_x = i;
			return (1);
		}
	}
	return (0);
}

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
		if (check_letter_pos(map[i], all->player.letter))
			all->player.start_y = i;
		while (len_line-- >= 0)
			tmp++;
	}
	map[i] = NULL;
	return (map);
}
