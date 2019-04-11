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


int		check_place(t_filler *fill, t_piece *token, int x, int y)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (++i < token->token->len)
	{
		if (fill->map[token->token->x[i] + x][token->token->y[i] + y] ==
		fill->enemy)
			return (0);
		if (fill->map[token->token->x[i] + x][token->token->y[i] + y] ==
		fill->player)
			count++;
		if (count == 2)
			return (0);
	}
	if (!count)
		return (0);
	return (1);
}

t_vec	*fill_matrix(t_filler *fill, int x, int y, t_piece *token, int f)
{
	register int	i;
	register int	j;
	t_vec			*vec_coord;
	const char 		enemy = f ? fill->enemy : fill->player;
	const char 		player = f ? fill->player : fill->enemy;
	int 			**matrix;

	matrix = f ? fill->int_map : fill->int_enemy_map;
	vec_coord = ft_makevec();
	i  = -1;
	while (++i < fill->map_x)
	{
		j = -1;
		while (++j < fill->map_y)
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

		i = -1;
		while (++i < (int)token->token->len)
			if (fill->map[token->token->x[i] + x][token->token->y[i] + y]
					!= player)
			{
				if (f)
					ft_vec_push_back(vec_coord, token->token->x[i] + x,
						token->token->y[i] + y);
				matrix[token->token->x[i] + x][token->token->y[i] + y] = f ? 0 : -2;
			}
	return (vec_coord);
}

int		find_optimal(t_filler *fill, t_vec *vec_coord, int f)
{
	const int		bypass[3] = {-1, 0, 1};
	register int	j;
	register int	i;
	int 			sum;
	int 			**matrix;


	sum = 0;
	matrix = f ? fill->int_map : fill->int_enemy_map;
	while (vec_coord->len)
	{
		i = -1;
		while (++i < 3)
		{
			j = -1;
			while (++j < 3)
				if (vec_coord->x[0] + bypass[i] < fill->map_x &&
					vec_coord->y[0] + bypass[j] < fill->map_y
					&& vec_coord->x[0] + bypass[i] >= 0
					&& vec_coord->y[0] + bypass[j] >= 0
					&& *(*(matrix + vec_coord->x[0] + bypass[i])
					+ vec_coord->y[0] + bypass[j]) == -1)
				{
					ft_vec_push_back(vec_coord, vec_coord->x[0] + bypass[i],
					vec_coord->y[0] + bypass[j]);
					*(*(matrix + vec_coord->x[0] + bypass[i]) + vec_coord->y[0] + bypass[j])
					= matrix[vec_coord->x[0]][vec_coord->y[0]] + 1;
					sum += matrix[vec_coord->x[0]][vec_coord->y[0]] + 1;
				}
		}
		ft_vec_pop_front(vec_coord);
	}
/*** COLOR MATRIX ***
	for (int i = 0; i < fill->map_x; i++)
	{
		for (int j = 0; j < fill->map_y; j++)
			if (matrix[i][j] == -2)
				printf("\033[31;0m%3d\033[0m", matrix[i][j]);
			else if (matrix[i][j] == -1)
				printf("\033[34;0m%3d\033[0m", matrix[i][j]);
			else if (matrix[i][j] == 0)
				printf("%3d", matrix[i][j]);
			else
				printf("\033[33;0m%3d\033[0m", matrix[i][j]);
		printf("\n");
	}
	printf("\n");*/
/*	int y = 0;
	for (int i = 0; i < fill->map_x; i++)
		for (int j = 0; j < fill->map_y; j++)
			y+= fill->int_map[i][j];

	printf("%d %d\n", sum , y);*/
	ft_free_vec(&vec_coord);
	return (sum); // todo maybe sum should account enemy
}

int		ft_vm_overshoot(t_place coord, t_piece *token, t_filler *fill)
{
	/**todo free all struct**/
	ft_free_vec(&token->token);
	del_arr((void ***)&((fill->map)));
	del_arr((void ***)&(fill->int_enemy_map));
	del_arr((void ***)&(fill->int_map));
	ft_putnbr(coord.x);
	write (1, " ", 1);
	ft_putnbr(coord.y);
	write (1, "\n", 1);
	if (coord.min == 10000)
	{
		del_arr((void ***)&((fill->map)));
		del_arr((void ***)&(fill->int_enemy_map));
		del_arr((void ***)&(fill->int_map));
		return (0);
	}
	return (1);
}

int		ft_put_token(t_filler *fill, t_piece *token, t_place coord)
{
	register int	i;
	register int	j;
	int				temp;

	i = -1;
	while (++i + token->piece_x < fill->map_x)
	{
		j = -1;
		while (++j + token->piece_y < fill->map_y)
			if (check_place(fill, token, i, j))
			{
				temp = find_optimal(fill,fill_matrix(fill, i, j, token, 1), 1) -
				find_optimal(fill, fill_matrix(fill, i, j, token, 0), 0);
				if (temp < coord.min)
				{
					coord.min = temp;
					coord.x = i;
					coord.y = j;
				}
			}
	}
	return (ft_vm_overshoot(coord, token, fill));
}
