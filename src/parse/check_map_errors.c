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
