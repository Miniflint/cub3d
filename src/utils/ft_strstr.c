/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:11:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/08 12:11:17 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
