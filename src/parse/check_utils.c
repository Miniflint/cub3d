/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:28:36 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 19:07:27 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// fonction récursive qui va checker depuis la vue du personnage ce qu'il peut théoriquement voir
// ça appelle juste la fonction en carré à chaque itération
// exemple (départ case: 3|3
// ça va faire
// 3 - 1|3
// 2 - 1|3
// 3 + 1|3
// 4 + 1|3
// etc etc
// et ça va check (gauche|droite|haut|bas)
// pas compliqué non plus mais j'ai du y penser a cette beauté
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

// check la position d'une lettre sur la map
// sera utile si y'a des monstres, porte, porte de sortie etc etc etc
// utilisée pour prendre la pos du joueur
int	*letter_pos_on_map(char **map, char letter, int i[2])
{
	int	x;
	int	y;

	y = -1;
	i[0] = -1;
	i[1] = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == letter)
			{
				i[0] = y;
				i[1] = x;
			}
		}
	}
	return (i);
}

// nom explicite
int	check_map_height(char *str)
{
	int	i;
	int	height;

	i = -1;
	height = 0;
	while (str[++i])
	{
		if (str[i] == '\n')
			height++;
	}
	if (str[i] == '\0' && str[i - 1] != '\n')
		height++;
	return (height);
}

// fonction pour checker quel lettre le joueur est
// sera aussi utile pour orienter le joueur (north|sud|...)
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

// useless, delete later when no need anymore
// je l'utilise encore des fois donc faut pas la suppr mtn
void print_double_tab(char **array_double)
{
	int	i;

	i = -1;
	while (array_double[++i])
		printf("%s\n", array_double[i]);
	printf("\n");
}
