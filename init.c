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

t_vis		*init(void)
{
	t_vis	*param;

	if (!(param = (t_vis *)malloc(sizeof(t_vis))))
		return (NULL);
	SCREEN_WID = 1500;
	SCREEN_HEI = 1000;
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, SCREEN_WID, SCREEN_HEI, "GO FIGHT!");
	IMG_PTR = mlx_new_image(MLX_PTR, SCREEN_WID, SCREEN_HEI);
	_DATA = (int*)mlx_get_data_addr(IMG_PTR,
						&BITS_PER_PIXEL, &SIZE_LINE, &ENDIAN);
	return (param);
}
