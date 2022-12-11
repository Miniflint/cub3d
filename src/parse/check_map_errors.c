/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:33:22 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 17:00:13 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


void	check_path_player(char **map, int row, int col, char letter)
{
	if (row < 0 || col < 0 || !map || !map[row] || !map[row][col])
		return ;
	if (map[row][col] == FILL || map[row][col] == '1' || map[row][col] == ' ')
		return ;
	if (map[row][col] != letter)
			map[row][col] = FILL;
	check_path_player(map, row - 1, col, letter);
	check_path_player(map, row + 1, col, letter);
	check_path_player(map, row, col - 1, letter);
	check_path_player(map, row, col + 1, letter);
	return ;
}

void print_double_tab(char **array_double)
{
	int	i;

	i = -1;
	while (array_double[++i])
		printf("%s\n", array_double[i]);
	printf("\n");
}

int	check_view_player(t_all *all)
{
	char	**new_map;

	new_map = cp_map(all->map.map, all->map.map_height);
	if (!new_map)
		return (1);
	check_path_player(new_map, all->player.start_y,
		all->player.start_x, all->player.letter);
	print_double_tab(new_map);
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

char	check_player_letter(char *str)
{
	char	c;

	c = 0;
	if (ft_occurence(str, 'N'))
		c = 'N';
	else if (ft_occurence(str, 'S'))
		c = 'S';
	else if (ft_occurence(str, 'W'))
		c = 'W';
	else if (ft_occurence(str, 'E'))
		c = 'E';
	return (c);
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
