/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 03:07:40 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/24 03:07:40 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_line(void *param, int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
		while (y1 <= y2)
			_DATA[x1 * (SCREEN_WID) + y1++] = COLOR_LINE;
	else
		while (x1 <= x2)
			_DATA[x1++ * (SCREEN_WID) + y1] = COLOR_LINE;

}

void	print_matrix(t_game *game, void	*param)
{
	register int i;
	register int j;

	i = 0;
	j = 0;
	while (i < SCREEN_HEI )
	{
		draw_line(param, i, 0, i , SCREEN_HEI);
		i += game->scale_x;
	}
	while (j < SCREEN_WID - 500)
	{
		draw_line(param, 0, j, SCREEN_HEI - 1, j);
		j += game->scale_y;
	}
}

int 	ft_exp_background(void *p, t_game *game)
{
	t_vis *param;
	int x;
	int y;

	param = p;
	x = -1;
	while (++x < SCREEN_HEI)
	{
		y = -1;
		while (++y < SCREEN_WID)
			if (y <  SCREEN_WID - 500)
				param->data[x * SCREEN_WID + y] = COLOR_BACKGROUND;
			else
				param->data[x * SCREEN_WID + y] = COLOR_BACKGROUND;
	}
	ranking_players(param, game);
	print_matrix(game, param);

	return (1);
}

void	color_cell(void *param, int color, int x, int y, t_game *game)
{
	int i;
	int j;

	i = 0;
	while (++i < game->scale_x)
	{
		j = 0;
		while (++j < game->scale_y)
			_DATA[(i + x * game->scale_x) * (SCREEN_WID) + j + y * game->scale_y] = color;
	}
}