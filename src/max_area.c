/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_area.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 13:17:22 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/28 13:17:22 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_func.h"

int		max_area(int **matrix, int map_x, int map_y)
{
	int count;
	int i;
	int j;

	count = 0;
	i = -1;
	while (++i < map_x)
	{
		j = -1;
		while (++j < map_y)
			if (matrix[i][j] == -1)
				++count;
	}
	return (count);
}

void	fill_coord(t_place *coord, t_filler *fill, int i, int j)
{
	coord->area = max_area(fill->int_enemy_map, fill->map_x, fill->map_y);
	coord->x = i;
	coord->y = j;
}
