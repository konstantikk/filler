/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:25:20 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/03 13:25:24 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_func.h"

t_filler		*ft_read(t_filler *fill)
{
	char	*line;
	char	*buff;

	get_next_line(0, &buff);
	line = buff;
	while (*line != 0)
	{
		if (ft_isdigit(*line))
		{
			fill->map_x = ft_atoi(line);
			line += ft_intlen(fill->map_x);
			fill->map_y = ft_atoi(line);
			break ;
		}
		++line;
	}
	ft_strdel(&buff);
	get_next_line(0, &line);
	ft_strdel(&line);
	fill->map = create_map(fill, fill->map);
	return (fill);
}

t_piece			*read_token(t_piece *token)
{
	char	*line;
	int		i;
	char	*buff;

	get_next_line(0, &buff);
	line = buff;
	line = ft_strchr(line, ' ');
	token->piece_x = ft_atoi(line);
	line = ft_strchr(++line, ' ');
	token->piece_y = ft_atoi(line);
	ft_strdel(&buff);
	if (!(token->piece = create_char_map(token->piece_x, token->piece_y)))
		return (NULL);//todo
	i = -1;
	while (++i < token->piece_x)
	{
		get_next_line(0, &buff);
		*(token->piece + i) = ft_strcpy(*(token->piece + i), buff);
		ft_strdel(&buff);
	}
	token->token = create_coord_token(token->piece, token);
	del_char_arr(&(token->piece), token->piece_x);
	return (token);
}

t_vec			*create_coord_token(char **piece, t_piece *token)
{
	register int	i;
	register int	j;
	t_vec			*tok_coord;
	const int		piece_y = token->piece_y;
	const int		piece_x = token->piece_x;

	tok_coord = ft_makevec();//todo
	i = -1;
	while (++i < piece_x)
	{
		j = -1;
		while (++j < piece_y)
			if (piece[i][j] == '*')
				ft_vec_push_back(tok_coord, i, j);// todo
	}
	return (tok_coord);
}
