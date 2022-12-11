/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:21:27 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/09 13:49:55 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Déclare une statique
// si le parametre envoyé est un pointeur sur la struct t_all
// alors la statique est update et va garder en mémoire son pointeur
// si la valeur est NULL r'envoie l'ancien pointeur de la structure
// utile pour ne jamais perdre la structure et pouvoir l'appeler partout
// voir main dans src/main/main.c
// exemple
// t_all	all;
//
// ft_get_all(&all); // attribue ici la structure pour ne jamais la perdre
//
/* (dans une autre fonction) */
// blablabla..
// bla..
// t_all	*all;
//
// all = ft_get_all(NULL); // récupére le pointeur de la struct déclarée ailleurs (voir ci dessus)
// altérnative:
// ft_get_all(NULL)->map.map // récupére la map (oui ça marche aussi comme ça)
t_all	*ft_get_all(t_all *all)
{
	static t_all	*new_all;
	
	if (all)
		new_all = all;
	return (new_all);
}
