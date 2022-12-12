/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:35:03 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 18:28:49 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// lire le fichier 1 par 1
// flemme d'utiliser get next line alors que j'ai ça qui marche bien
// (quand j'écris le commentaire je me dis que gnl aurai été utile pour parser
// les couleurs etc
// mais que ça aurai été chiant pour la map donc avis mitigé avec moi même)
// ft_strjoin in src/utils/ft_strjoin.c
static char	*quick_read_map(int fd)
{
	char	*str;
	char	*str_cpy;
	int		rd;
	char	buf[2];

	rd = read(fd, buf, 1);
	buf[1] = 0;
	str = ft_strdup(buf);
	while (rd)
	{
		rd = read(fd, buf, 1);
		if (!rd)
			break ;
		buf[1] = 0;
		str_cpy = str;
		str = ft_strjoin(str_cpy, buf);
		free(str_cpy);
		str_cpy = NULL;
	}
	close(fd);
	return (str);
}

// check si le fichier existe
// crée le FD et renvoie directement la chaine malloquée
char	*read_map(char *path_map)
{
	int		fd;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	return (quick_read_map(fd));
}
