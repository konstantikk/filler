/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 21:01:49 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/27 21:01:49 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	read_token(t_game *token)
{
	char	*line;
	int		i;
	char	*buff;

	get_next_line(0, &buff);
	line = buff;
	if (!(line = ft_strchr(line, ' ')))
		return ;
	token->piece_x = ft_atoi(line);
	line = ft_strchr(++line, ' ');
	token->piece_y = ft_atoi(line);
	ft_strdel(&buff);
	if (!(token->piece = create_char_map(token->piece_x, token->piece_y)))
		return ;
	i = -1;
	while (++i < token->piece_x)
	{
		get_next_line(0, &buff);
		*(token->piece + i) = ft_strcpy(*(token->piece + i), buff);
		ft_strdel(&buff);
	}
	token->token_scale = 600 / (token->map_x > token->map_y ?
		token->map_x : token->map_y);
}

void	paint_token(t_game *token, void *param, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < token->piece_x)
	{
		j = -1;
		while (++j < token->piece_y)
		{
			if (token->piece[i][j] == '*')
				color_cell_token(param, color, i, j);
			else
				color_cell_token(param, COLOR_BACKGROUND, i, j);
		}
	}
}

void	color_cell_token(void *param, int color, int x, int y)
{
	int			i;
	int			j;
	t_vis		*p;
	int			token_scale;
	int			token_centre;

	p = (t_vis *)param;
	token_scale = p->game->token_scale;
	token_centre = (500 - p->game->piece_y * token_scale) / 2;
	i = 1;
	while (++i < token_scale)
	{
		j = 1;
		while (++j < token_scale)
			_DATA[(i + 350 + x * token_scale) * (SCREEN_WID) +
					j + 1000 + token_centre + y * token_scale] = color;
	}
}
