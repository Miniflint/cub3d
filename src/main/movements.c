/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:55:46 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/17 16:53:06 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
 * calcul les delta en fonction de la ou la personne regarde
 * je t'expliquerai quand on se voit parce que'c 'est un bordel pas croyable
 * quick explications -> voir la feuille excel
 * au lieu d'utiliser des degré j'utilise des radiants
 * ça permet de faire de belle choses comme avoir un cos / sin précis
 * y'a encore un petit bug au niveau de comment pi * 2 est géré et c'est chiant
 * le bug vient de
 (
	if (all->player.angle > (double)(M_PI * 2) - 0.01)
		all->player.angle = 0;
	else if (all->player.angle < 0.1)
		all->player.angle = (double)(M_PI * 2);
 )
 * j'arrive pas a trouver un bon moyen de faire en sorte que 
 * si l'angle est supérieur à PI * 2
 * bah l'angle doit etre 0
 * valeur max de angle doit être:  6.283184
 * et la valeur min doit être 0
 * enfaite j'ai trouvé en écrivant donc c'est bon
 * nouveau petit bug
 * je sais pas pourquoi mais le y ne bouge jamais
 * je verrai ça demain 
 */

// this function ROTATES the angle and direction vector (dx, dy)
double	calculus_view(t_all *all)
{
	if (all->player.angle > (double)(M_PI * 2))
		all->player.angle = 0;
	else if (all->player.angle < 0)
		all->player.angle = (double)(M_PI * 2);
	all->player.dx = DISTANCE * cos(all->player.angle);
	all->player.dy = DISTANCE * sin(all->player.angle);
	return (all->player.angle_per_key);
}

/*
 * Fonction pour faire bouger le joueur
 * Fonctionne environ sauf le bug mentionné ci dessus
 * je verrai ça demainß
 * oui plusieurs touche marchent en meme temps
 * oui je me suis fait chier pendant 2 heures
 * oui j'ai une feuille excel
 * oui j'veux mourir atm
*/
void	print_wth_is_that(t_raycast r)
{
	printf("\nIdk what the fuck this is: \n\t");
	printf("mp: %d - ", r.mp);
	printf("mx: %d - ", r.mx);
	printf("my: %d\n", r.my);
	printf("Idk what this is either: \n\t");
	printf("r: %d\n", r.r);
	printf("Rayon and angles: \n\t");
	printf("Angle: %f - ", r.angle);
	printf("Rayon x: %f - ", r.x);
	printf("Rayon y: %f - \n", r.y);
	printf("Offset: \n\t");
	printf("Offset x: %f - ", r.x_offset);
	printf("Offset y: %f\n", r.y_offset);
	printf("\n");
}

static void	fill_next_pos(t_all *all, double *npx, double *npy)
{
	if (all->player.moves.key_w)
	{
		*npx += all->player.dx;
		*npy += all->player.dy;
	}
	if (all->player.moves.key_a)
	{
		*npx += all->player.dy;
		*npy -= all->player.dx;
	}
	if (all->player.moves.key_s)
	{
		*npx -= all->player.dx;
		*npy -= all->player.dy;
	}
	if (all->player.moves.key_d)
	{
		*npx -= all->player.dy;
		*npy += all->player.dx;
	}
}

int	player_next_pos(t_all *all)
{
	double	cpx;
	double	cpy;
	int		inpx;
	int		inpy;
	char	**map;

	cpx = all->player.x;
	cpy = all->player.y;
	fill_next_pos(all, &cpx, &cpy);
	inpx = (int)cpx;
	inpy = (int)cpy;
	map = all->map.map;
	if (!map[inpy][inpx] || map[inpy][inpx] == '1')
		return (1);
	return (0);
}

void	move_with_key(t_all *all)
{
	if (all->player.moves.arr_right)
		all->player.angle += calculus_view(all);
	if (all->player.moves.arr_left)
		all->player.angle -= calculus_view(all);
	if (player_next_pos(all))
		return ;
	calculus_view(all);
	fill_next_pos(all, &all->player.x, &all->player.y);
	draw_map(all);
	drawray(all);
	print_wth_is_that(all->player.raycast);
	printf("y: %f - x: %f\tangle: %f\n", all->player.y, all->player.x, all->player.angle);
}

void	translate_key(int keycode, t_all *all, int value)
{
	if (keycode == K_Q || keycode == K_ESC)
		close_window();
	if (keycode == K_W)
		all->player.moves.key_w = value;
	if (keycode == K_A)
		all->player.moves.key_a = value;
	if (keycode == K_S)
		all->player.moves.key_s = value;
	if (keycode == K_D)
		all->player.moves.key_d = value;
	if (keycode == ARR_LEFT)
		all->player.moves.arr_left = value;
	if (keycode == ARR_RIGHT)
		all->player.moves.arr_right = value;
}

int	keyDowned(int keycode, t_all *all)
{
	translate_key(keycode, all, 1);
	move_with_key(all);
	return (0);
}

int	keyUpped(int keycode, t_all *all)
{
	translate_key(keycode, all, 0);
	return (0);
}
