/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:11:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 17:47:55 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// regarde si la chaine de char "substr" est contenue dans la chaine s1
// et renvoie un pointeur a celle ci si existante
char	*ft_strstr(char *s1, char *substr)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] && s1[i + j] == substr[j])
		{
			if (!substr[j + 1])
				return (&s1[i]);
			j++;
		}
		i++;
	}
	if (!s1[i])
		return (NULL);
	return (NULL);
}

// voir ft_strstr
// meme principe sauf que c'est modifié pour revenir en arrière
// si y'a des espace / tab devant 
char	*ft_strstr_map(char *s1, char *substr)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while ((s1[i + j] && s1[i + j] == substr[j]))
		{
			if (!substr[j + 1])
			{
				if (s1[i] && s1[i] == ' ')
					while (s1[i - 1] == ' ' || s1[i - 1] == '\t')
						i--;
				return (&s1[i]);
			}
			j++;
		}
		i++;
	}
	if (!s1[i])
		return (NULL);
	return (NULL);
}
