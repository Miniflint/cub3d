/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 03:31:53 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/09 13:49:54 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	new_str[i] = 0;
	return (new_str);
}

char	*ft_strldup(char *str, int size)
{
	int		i;
	char	*new_str;
	
	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * size + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		new_str[i] = str[i];
		if (!str[i])
			break ;
	}
	new_str[i] = 0;
	return (new_str);
}
