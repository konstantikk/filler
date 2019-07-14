/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 21:16:57 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/27 21:16:57 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	dead_string(t_vis *param, t_game *game)
{
	if (game->dead2 || game->dead1)
	{
		if (game->dead1)
			mlx_string_put(MLX_PTR, WIN_PTR, game->player1_step,
					50, COLOR_P1, "DEAD");
		if (game->dead2)
			mlx_string_put(MLX_PTR, WIN_PTR, game->player2_step,
					50, COLOR_P2, "DEAD");
	}
}

void	print_string(t_game *game, t_vis *param)
{
	int			x;
	const int	y = SCREEN_WID - 500 + 5;

	x = 80;
	dead_string(param, game);
	mlx_string_put(MLX_PTR, WIN_PTR, game->player1_step, x,
			COLOR_P1, game->player1);
	mlx_string_put(MLX_PTR, WIN_PTR, game->player2_step, x,
			COLOR_P2, game->player2);
	x += 40;
	mlx_string_put(MLX_PTR, WIN_PTR, y, x, 0xffffff, "Score :");
	mlx_string_put(MLX_PTR, WIN_PTR, y + 100, x, COLOR_P1,
			ft_itoa(game->score1));
	mlx_string_put(MLX_PTR, WIN_PTR, y + 350, x, COLOR_P2,
			ft_itoa(game->score2));
	x += 40;
	mlx_string_put(MLX_PTR, WIN_PTR, y, x, 0xffffff, "Area :");
	print_area_string(game, param);
}

void	who_line(t_vis *param, size_t len, t_game *game, int f)
{
	size_t		i;
	const int	x = 100;

	i = 0;
	if (game->who == 'O')
		while (i < len * 10)
			_DATA[i++ + x * SCREEN_WID + game->player1_step] = f ?
					COLOR_P1 : COLOR_MAP;
	else
		while (i < len * 10)
			_DATA[i++ + x * SCREEN_WID + game->player2_step] = f ?
					COLOR_P2 : COLOR_MAP;
}
