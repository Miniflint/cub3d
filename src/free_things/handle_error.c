/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:23:06 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/08 12:24:15 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


// fonction pour afficher un message d'erreur
// ensuite quitter le programme en oubliant pas de free tout
void	handle_error(char *str)
{
	printf("./cub3d Error\n\t%s\n", str);
	free_all();
	exit(0);
}
