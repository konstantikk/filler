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

void	find_your_place(t_filler *fill)
{
	const char		c = fill->player ? 'X' : 'O';
	const char 		ec = fill->player ? 'O' : 'X';
	register int	i;
	register int	j;

	i = 0;
	while (i < fill->map_x)
	{
		j = 0;
		while (j < fill->map_y)
		{
			if (fill->map[i][j] == c)
			{
				fill->my_x = i;
				fill->my_y = j;
			}
			else if (fill->map[i][j] == ec)
			{
				fill->en_x = i;
				fill->en_y = j;
			}
			j++;
		}
		i++;
	}
}

int 	check_place(t_filler *fill, t_piece	*token, int x, int y)
{
	int i;
	static int count;

	count = 0;
	i = 0;
	if (x + token->piece_x > fill->map_x || y + token->piece_y > fill->map_y)
		return (0);
	while (i < (int)token->token->len)
	{
		if (fill->map[token->token->x[i] + x][token->token->y[i] + y] ==
		fill->enemy)
			return (0);
		if (count > 1)
			return (0);
		if (fill->map[token->token->x[i] + x][token->token->y[i] + y] ==
		fill->player)
			count++;
		++i;
	}
	if (!count)
		return (0);
	return (1);
}

char	**ft_put_token(t_filler *fill, t_piece *token)
{
	int			i;
	int			j;

	i = 0;
	while (i < fill->map_x)
	{
		j = 0;
		while (j < fill->map_y)
		{
			if (check_place(fill, token, i, j))
			{

			//	printf(".");

			}
			//else
				//printf("-");
			j++;
		}
		//printf("\n");
		i++;
	}
	return (0);
}
