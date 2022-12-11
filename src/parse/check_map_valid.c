/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:58:16 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 17:25:41 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	norminette_i_hate_u(char **m, int i, int j)
{
	if ((m[i - 1] && m[i - 1][j] && m[i - 1][j] == ' ')
		|| (m[i + 1] && m[i + 1][j]
		&& m[i + 1][j] == ' ') || (m[i][j - 1] && m[i][j - 1] == ' ')
		|| (m[i][j + 1] && m[i][j + 1] == ' '))
		return (1);
	return (0);
}

int	check_map_open(char **modified_map)
{
	int	i;
	int	j;

	i = -1;
	while (modified_map[++i])
	{
		j = -1;
		while (modified_map[i][++j])
		{
			if (modified_map[i][j] == FILL)
			{
			}
		}
	}
}