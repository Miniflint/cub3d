#include "../../inc/cub3d.h"

static void	txtr_nully(t_all *all)
{
	int	i;

	all->txtr.f = NULL;
	all->txtr.c = NULL;
	all->txtr.no = NULL;
	all->txtr.so = NULL;
	all->txtr.we = NULL;
	all->txtr.ea = NULL;
	i = -1;
	while (++i < 3)
	{
		all->txtr.f_int[i] = -1;
		all->txtr.c_int[i] = -1;
	}
}

static void	map_nully(t_all *all)
{
	all->map.map = NULL;
	all->map.file = NULL;
	all->map.map_array = NULL;
}

static void	player_nully(t_all *all)
{
	all->player.letter = '\0';
	all->player.start_x = 0;
	all->player.start_y = 0;
	all->player.x = 0;
	all->player.y = 0;
}

void	everything_null(t_all *all)
{
	txtr_nully(all);
	map_nully(all);
	player_nully(all);
}
