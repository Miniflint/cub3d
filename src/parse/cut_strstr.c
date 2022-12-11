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

char	*cut_strstr_dup(char *str, int c, int map)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	if (!map)
		while (str[i] == ' ' || str[i] == '\t')
			str++;
	while (str[i] && str[i] != c)
		i++;
	if (i == 0)
		return (NULL);
	return (ft_strldup(str, i));
}
