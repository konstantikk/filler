/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:24:01 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/04 18:24:01 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_func.h"

int		check_place(t_filler *fill, t_vec *token, int x, int y)
{
	int			i;
	int			count;
	const int	len = (int)token->len;
	char		**map;

	map = fill->map;
	count = 0;
	i = -1;
	while (++i < len)
	{
		if (map[token->x[i] + x][token->y[i] + y] == fill->enemy)
			return (0);
		if (map[token->x[i] + x][token->y[i] + y] == fill->player)
			count++;
		if (count == 2)
			return (0);
	}
	if (!count)
		return (0);
	return (1);
}

int		recount_int_map(t_filler *fill, int map_x, int map_y)
{
	int i;
	int j;
	int sum;

	sum = 0;
	i = -1;
	while (++i < map_x)
	{
		j = -1;
		while (++j < map_y)
		{
			if (fill->int_enemy_map[i][j] == -1)
				fill->int_map[i][j] = -100;
			sum += fill->int_map[i][j];
		}
	}
	return (sum);
}

int		recount_int_enemy_map(int **matrix, int map_x, int map_y)
{
	int i;
	int j;
	int sum;

	sum = 0;
	i = -1;
	while (++i < map_x)
	{
		j = -1;
		while (++j < map_y)
			if (matrix[i][j] == -1)
				sum += (map_x + map_y * 2);
			else
				sum += matrix[i][j];
	}
	return (sum);
}

int		ft_vm_overshoot(t_place coord)
{
	ft_putnbr(coord.x);
	write(1, " ", 1);
	ft_putnbr(coord.y);
	write(1, "\n", 1);
	if (coord.x == 6666)
		return (0);
	return (1);
}

int		ft_put_token(t_filler *fill, t_piece *token, t_place coord)
{
	register int	i;
	register int	j;
	int				temp;
	t_vec			*tok;

	tok = token->token;
	i = -1;
	while (++i + token->piece_x <= fill->map_x)
	{
		j = -1;
		while (++j + token->piece_y <= fill->map_y)
			if (check_place(fill, tok, i, j))
			{
				temp = find_optimal(fill, fill_my_map(fill, i, j, tok), 1)
				- find_optimal(fill, fill_enemy_map(fill, i, j, tok), 0);
				if (temp < coord.min && (coord.min = temp))
				{
					coord.x = i;
					coord.y = j;
				}
			}
	}
	return (ft_vm_overshoot(coord));
}
