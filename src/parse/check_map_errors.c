/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:33:22 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/08 12:33:37 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#define FILL 'k'


void	check_path_player(char **map, int row, int col, char letter)
{
	if (row < 0 || col < 0 || !map[row][col])
		return ;
	if (map[row][col] == FILL || map[row][col] != '0')
		return ;
	if (map[row][col] != letter)
		map[row][col] = FILL;
	check_path_player(map, row - 1, col, letter);
	check_path_player(map, row + 1, col, letter);
	check_path_player(map, row, col - 1, letter);
	check_path_player(map, row, col + 1, letter);
	return ;
}

int	check_view_player(t_all *all)
{
	char	**new_map;

	new_map = all->map.map;
	check_path_player(new_map, all->player.start_x,
		all->player.start_y, all->player.letter);
	return (0);
}

// player can be: N - S - W - E
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
	if (ft_strlen_uc(str, 'N'))
		return('N');
	if (ft_strlen_uc(str, 'S'))
		return ('S');
	if (ft_strlen_uc(str, 'W'))
		return ('W');
	if (ft_strlen_uc(str, 'E'))
		return ('E');
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
