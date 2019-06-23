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

void	draw_line(void *param, t_coord *coord)
{
	const int	x2 = coord->x2;
	const int	y2 = coord->y2;
	int			x1;
	int			y1;

	x1 = coord->x1;
	y1 = coord->y1;
	if (x1 == x2)
		while (y1 <= y2)
			_DATA[x1 * (SCREEN_WID) + y1++] = COLOR_LINE;
	else
		while (x1 <= x2)
			_DATA[x1++ * (SCREEN_WID) + y1] = COLOR_LINE;
}

void	print_matrix(t_game *game, void *param)
{
	int		i;
	int		j;
	int		k;
	t_coord	*coord;

	k = 0;
	i = game->centre_x;
	j = game->centre_y;
	while (k++ < game->map_x + 1)
	{
		coord = init_coord(i, j, i, game->map_y * game->scale + game->centre_y);
		draw_line(param, coord);
		free(coord);
		i += game->scale;
	}
	k = 0;
	while (k++ < game->map_y + 1)
	{
		coord = init_coord(game->centre_x, j, game->map_x * game->scale +
				game->centre_x, j);
		draw_line(param, coord);
		j += game->scale;
		free(coord);
	}
}

int		ft_exp_background(void *p, t_game *game)
{
	t_vis	*param;
	int		x;
	int		y;

	param = p;
	x = -1;
	while (++x < SCREEN_HEI)
	{
		y = -1;
		while (++y < SCREEN_WID)
			if (y < (SCREEN_WID - 500))
				param->data[x * SCREEN_WID + y] = COLOR_BACKGROUND;
			else
				param->data[x * SCREEN_WID + y] = COLOR_MAP;
	}
	ranking_players(param, game);
	print_matrix(game, param);
	return (1);
}

void	color_cell(void *param, int color, int x, int y)
{
	int		i;
	int		j;
	t_game	*game;
	t_vis	*p;

	p = (t_vis *)param;
	game = p->game;
	i = 1;
	while (++i < game->scale)
	{
		j = 1;
		while (++j < game->scale)
			_DATA[(i + game->centre_x + x * game->scale) * (SCREEN_WID) + j +
			game->centre_y + y * game->scale] = color;
	}
}

void	paint_area(t_vis *param, t_game *game, int **int_map)
{
	const int	map_x = game->map_x;
	const int	map_y = game->map_y;
	int			i;
	int			j;

	i = -1;
	while (++i < map_x)
	{
		j = -1;
		while (++j < map_y)
			if (int_map[i][j] == -1)
			{
				if (game->who == 'O')
					color_cell(param, COLOR_FILL1, i, j);
				else
					color_cell(param, COLOR_FILL2, i, j);
			}
	}
}
