/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_strstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:01:13 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 19:01:00 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// quel beauté cette fonction je l'aime de tout mon coeur
// elle prend un pointeur d'une chaine de char (non malloquée, sinon leaks issues)
// offset si y'a besoin (donc l'avance, utile pour parser le NO, SO, WE, EA, C, F)
// si on est pas sur la map, skip space pour si y'en a
// pour récupérer que la bonne chaine de char (NO ./texture/path)
// ( ./texture/path)
// (./texture/path)
// et renvoie une chaine de char malloquée de la chaine avec strldup
// voir ft_strldup dans src/utils/ft_strdup.c
char	*cut_strstr_dup(char *str, int c, int map, int offset)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	str += offset;
	if (!map)
		while (str[i] == ' ' || str[i] == '\t')
			str++;
	while (str[i] && str[i] != c)
		i++;
	if (i == 0)
		return (NULL);
	return (ft_strldup(str, i));
}
