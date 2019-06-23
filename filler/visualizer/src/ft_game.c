/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 21:20:38 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/27 21:20:38 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	ranking_players(void *param, t_game *game)
{
	register int	i;
	register int	j;
	t_vis			*p;

	i = -1;
	p = (t_vis *)param;
	p->game = game;
	while (++i < game->map_x)
	{
		j = -1;
		while (++j < game->map_y)
			if (game->map[i][j] == game->p1)
				color_cell(param, COLOR_P1, i, j);
			else if (game->map[i][j] == game->p1 + 32)
				color_cell(param, COLOR_PP1, i, j);
			else if (game->map[i][j] == game->p2)
				color_cell(param, COLOR_P2, i, j);
			else if (game->map[i][j] == game->p2 + 32)
				color_cell(param, COLOR_PP2, i, j);
	}
}

void	check_area(t_game *game, t_vis *param)
{
	t_vec		*vec;
	const int	map_x = game->map_x;
	const int	map_y = game->map_y;

	if (game->who == 'O')
	{
		vec = fill_matrix(game->int_map, game->p2, game->p1, game);
		game->int_map = check_displacement(vec, game->int_map, map_x, map_y);
		game->area1 = (float)count_area(game, game->int_map) /
				(game->map_y * game->map_x);
	}
	else if (game->who == 'X')
	{
		vec = fill_matrix(game->int_map, game->p1, game->p2, game);
		game->int_map = check_displacement(vec, game->int_map, map_x, map_y);
		game->area2 = (float)count_area(game, game->int_map) /
				(game->map_y * game->map_x);
	}
	paint_area(param, game, game->int_map);
}

int		game_over(t_vis *param, t_game *game)
{
	char *buff;

	if (!get_next_line(0, &buff))
	{
		mlx_string_put(MLX_PTR, WIN_PTR, game->player1_step + 100, 250,
				COLOR_WIN, "WIN");
		mlx_string_put(MLX_PTR, WIN_PTR, game->player1_step + 150, 250,
				COLOR_WIN, (game->score1 > game->score2) ? game->player1 :
game->player2);
		ft_hook_loop(param);
		mlx_loop(MLX_PTR);
		return (0);
	}
	if (!(ft_strchr(buff, 'l')))
		return (0);
	ft_strdel(&buff);
	return (1);
}

void	maybe_sm1_dead(t_vis *param, t_game *game)
{
	if (game->score1 - game->score2 >= 2)
	{
		mlx_string_put(MLX_PTR, WIN_PTR, game->player2_step, 50, COLOR_P2,
				"DEAD");
		if (game->score1 - game->score2 == 2 && !game->dead1 && !game->dead2)
			paint_token(game, param, COLOR_P2);
		game->dead2 = 1;
	}
	if (game->score2 - game->score1 >= 2)
	{
		mlx_string_put(MLX_PTR, WIN_PTR, game->player1_step, 50, COLOR_P1,
				"DEAD");
		if (game->score2 - game->score1 == 2 && !game->dead2 && !game->dead1)
			paint_token(game, param, COLOR_P1);
		game->dead1 = 1;
	}
}

void	count_score(t_game *game)
{
	char	*buff;

	get_next_line(0, &buff);
	if (ft_strchr(buff, '=') || ft_strchr(buff, 'g'))
	{
		if (ft_strchr(buff, 'O') && !ft_strchr(buff, '='))
		{
			game->who = 'O';
			if (!game->dead1)
				game->score1++;
		}
		else if (ft_strchr(buff, 'X') && !ft_strchr(buff, '='))
		{
			if (!game->dead2)
				game->score2++;
			game->who = 'X';
		}
		if (game->dead1)
			game->who = 'X';
		else if (game->dead2)
			game->who = 'O';
	}
	ft_strdel(&buff);
}
