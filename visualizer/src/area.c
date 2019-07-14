/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 22:36:56 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/25 22:36:56 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_vec	*fill_matrix(int **matrix, char enemy, char player, t_game *fill)
{
	register int	i;
	register int	j;
	t_vec			*vec_coord;

	vec_coord = ft_makevec();
	i = -1;
	while (++i < fill->map_x)
	{
		j = -1;
		while (++j <= fill->map_y)
		{
			if (fill->map[i][j] == enemy || fill->map[i][j] == enemy + 32)
				matrix[i][j] = -2;
			else if (fill->map[i][j] == player ||
			fill->map[i][j] == player + 32)
			{
				ft_vec_push_back(vec_coord, i, j);
				matrix[i][j] = 0;
			}
			else
				matrix[i][j] = -1;
		}
	}
	return (vec_coord);
}

int		**check_displacement(t_vec *vec_coord, int **matrix, int map_x,
		int map_y)
{
	register int	j;
	register int	i;
	int				x;
	int				y;
	const int		b[3] = {-1, 0, 1};

	while (vec_coord->len)
	{
		i = -1;
		x = vec_coord->x[0];
		y = vec_coord->y[0];
		while (++i < 3)
		{
			j = -1;
			while (++j < 3)
				if (x + b[i] < map_x && y + b[j] < map_y && x + b[i] >= 0
				&& y + b[j] >= 0 && *(*(matrix + x + b[i]) + y + b[j]) == -1)
				{
					ft_vec_push_back(vec_coord, x + b[i], y + b[j]);
					*(*(matrix + x + b[i]) + y + b[j]) = matrix[x][y] + 1;
				}
		}
		ft_vec_pop_front(vec_coord);
	}
	return (matrix);
}

int		count_area(t_game *game, int **map)
{
	int area;
	int	i;
	int j;

	area = 0;
	i = -1;
	while (++i < game->map_x)
	{
		j = -1;
		while (++j < game->map_y)
			if (map[i][j] == 0 || map[i][j] == -1)
				area++;
	}
	return (area);
}

void	print_area_string(t_game *game, t_vis *param)
{
	const int	y = SCREEN_WID - 500 + 5;

	mlx_string_put(MLX_PTR, WIN_PTR, y + 100, 160, COLOR_P1,
			ft_itoa((int)(game->area2 * 100)));
	mlx_string_put(MLX_PTR, WIN_PTR, SCREEN_WID - 395 + 30, 160, COLOR_P1, "%");
	mlx_string_put(MLX_PTR, WIN_PTR, y + 350, 160, COLOR_P2,
			ft_itoa((int)(game->area1 * 100)));
	mlx_string_put(MLX_PTR, WIN_PTR, y + 350 + 30, 160, COLOR_P2, "%");
}
