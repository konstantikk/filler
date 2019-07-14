/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:23:45 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/19 22:02:26 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_vis		*init(t_game *game)
{
	t_vis	*param;
	int		step;

	if (!(param = (t_vis *)malloc(sizeof(t_vis))))
		return (NULL);
	SCREEN_WID = 1540;
	SCREEN_HEI = 1040;
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, SCREEN_WID, SCREEN_HEI, "GO FIGHT!");
	IMG_PTR = mlx_new_image(MLX_PTR, SCREEN_WID, SCREEN_HEI);
	_DATA = (int*)mlx_get_data_addr(IMG_PTR,
						&BITS_PER_PIXEL, &SIZE_LINE, &ENDIAN);
	game->score1 = -1;
	game->score2 = -1;
	game->centre_x = (SCREEN_HEI - game->map_x * game->scale) / 2;
	game->centre_y = ((SCREEN_WID - 500) - game->map_y * game->scale) / 2;
	step = (SCREEN_WID - 500 - ft_strlen(game->player1) -
			ft_strlen(game->player2)) / 6;
	game->player1_step = SCREEN_WID - 500 - 40 + step / 2;
	game->player2_step = SCREEN_WID - 500 - 40 + 2 * step +
			ft_strlen(game->player1);
	return (param);
}
