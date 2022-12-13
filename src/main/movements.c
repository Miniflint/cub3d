/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:55:46 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/13 17:15:41 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_with_key(t_all *all)
{
	if (all->player.moves.key_w)
		all->player.y += (double)0.03;
	if (all->player.moves.key_a)
		all->player.x -= (double)0.03;
	if (all->player.moves.key_s)
		all->player.y -= (double)0.03;
	if (all->player.moves.key_d)
		all->player.x += (double)0.03;
	if (all->player.moves.arr_left)
		all->player.angle += (int)0.03;
	if (all->player.moves.arr_right)
		all->player.angle -= (double)0.02;
	printf("y: %f - x: %f\tangle: %f\n", all->player.y, all->player.x, all->player.angle);
	if (!all->map.map[(int)all->player.y][(int)all->player.x]
		|| all->map.map[(int)all->player.y][(int)all->player.x] == '1')
		printf("U should be here btw\n");
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
	move_with_key(all);
}

int	keyDowned(int keycode, t_all *all)
{
	translate_key(keycode, all, 1);
	return (0);
}

int	keyUpped(int keycode, t_all *all)
{
	translate_key(keycode, all, 0);
	return (0);
}
