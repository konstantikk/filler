/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:06:04 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/19 22:03:01 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		ft_game_loop(void *p)
{
	t_game	*game;
	t_vis	*param;

	param = (t_vis *)p;
	game = param->game;
	count_score(game);
	maybe_sm1_dead(param, game);
	if (!game_over(param, game))
		return (0);
	create_map(game, game->map);
	ranking_players(param, game);
	read_token(game);
	check_area(game, param);
	who_line(param, ft_strlen(game->who == 'O' ? game->player1 : game->player2),
			game, 1);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	who_line(param, ft_strlen(game->who == 'O' ? game->player1 : game->player2),
			game, 0);
	print_string(game, param);
	return (1);
}

int		main(void)
{
	t_vis	*param;
	t_game	*game;

	game = (t_game*)ft_memalloc(sizeof(t_game));
	read_gamers(game);
	param = init(game);
	game->map = create_map(game, game->map);
	ft_exp_background(param, game);
	read_token(game);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	param->game = game;
	mlx_loop_hook(MLX_PTR, ft_game_loop, param);
	ft_hook_loop(param);
	mlx_loop(MLX_PTR);
	return (0);
}
