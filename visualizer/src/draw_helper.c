/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:56:34 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/28 15:56:34 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_coord		*init_coord(int x1, int y1, int x2, int y2)
{
	t_coord *coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	coord->x1 = x1;
	coord->y1 = y1;
	coord->x2 = x2;
	coord->y2 = y2;
	return (coord);
}
