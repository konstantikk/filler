/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_place.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:49:20 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/28 14:54:48 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_func.h"

t_vec	*fill_matrix(int **matrix, char enemy, char player, t_filler *fill)
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
			if (fill->map[i][j] == enemy)
				matrix[i][j] = -2;
			else if (fill->map[i][j] == player)
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

t_vec	*fill_enemy_map(t_filler *fill, int x, int y, t_vec *token)
{
	int				i;
	t_vec			*vec_coord;
	int				**matrix;
	const char		enemy = fill->player;
	const char		player = fill->enemy;

	matrix = fill->int_enemy_map;
	vec_coord = fill_matrix(matrix, enemy, player, fill);
	i = -1;
	while (++i < (int)token->len)
		if (fill->map[token->x[i] + x][token->y[i] + y] != player)
			matrix[token->x[i] + x][token->y[i] + y] = -2;
	return (vec_coord);
}

t_vec	*fill_my_map(t_filler *fill, int x, int y, t_vec *token)
{
	int				i;
	t_vec			*vec_coord;
	int				**matrix;
	const char		enemy = fill->enemy;
	const char		player = fill->player;

	matrix = fill->int_map;
	vec_coord = fill_matrix(matrix, enemy, player, fill);
	i = -1;
	while (++i < (int)token->len)
		if (fill->map[token->x[i] + x][token->y[i] + y] != player)
		{
			ft_vec_push_back(vec_coord, token->x[i] + x, token->y[i] + y);
			matrix[token->x[i] + x][token->y[i] + y] = 0;
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

int		find_optimal(t_filler *fill, t_vec *vec_coord, int f)
{
	int			**matrix;
	const int	map_x = fill->map_x;
	const int	map_y = fill->map_y;
	int			sum;

	matrix = f ? fill->int_map : fill->int_enemy_map;
	matrix = check_displacement(vec_coord, matrix, map_x, map_y);
	sum = f ? recount_int_map(fill, map_x, map_y) :
	recount_int_enemy_map(matrix, map_x, map_y);
	ft_free_vec(&vec_coord);
	return (sum);
}
