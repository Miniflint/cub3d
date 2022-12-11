/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:33:22 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 19:07:15 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_view_player(t_all *all)
{
	char	**new_map;

	new_map = cp_map(all->map.map, all->map.map_height);
	if (!new_map)
		return (1);
	check_path_player(new_map, all->player.start_y,
		all->player.start_x, all->player.letter);
	print_double_tab(new_map);
	if (check_map_open(new_map))
	{
		free_double_tab(new_map);
		handle_error("Map wrongly formatted");
	}
	free_double_tab(new_map);
	return (0);
}

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

int	contains_fill(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == FILL)
			return (1);
	return (0);
}

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
