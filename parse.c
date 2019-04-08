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

# include "filler_func.h"

void		find_your_player(t_filler *fill)
{
	char		*line;

	get_next_line(0, &line);
	line = ft_strchr(line, 'p');
	fill->player = (*(++line) == '1') ? 'O' : 'X';
	fill->enemy = (fill->player == 'X') ? 'O' : 'X';
}

t_filler	ft_read(t_filler fill)
{
	char		*line;

	get_next_line(0, &line);
	while (*line != 0)
	{
		if (ft_isdigit(*line))
		{
			fill.map_x = ft_atoi(line);
			line += ft_intlen(fill.map_x);
			fill.map_y = ft_atoi(line);
			break ;
		}
		++line;
	}
	get_next_line(0, &line);
	free(line);
	return (fill);
}

char 	**create_map(t_filler *fill, char **map)
{
	char	*line;
	int		i;

	if (map == NULL)
	{
		if (!(map = (char **)ft_memalloc(fill->map_x + 1)))
			return (NULL); //todo
		i = 0;
		while (i < fill->map_x)
			if (!(*(map + i++) = (char *)ft_memalloc(fill->map_y + 1)))
				return (NULL); //todo
		*(map + i) = NULL;
	}
	i = 0;
	while (*(map + i))
	{
		get_next_line(0, &line);
		line = ft_strchr(line, ' ');
		*(map + i) = ft_strcpy(*(map + i), ++line);
		i++;
	}
	return (map);
}

t_vec		*create_coord_token(char **piece, t_piece *token)
{
	int i;
	int j;
	t_vec *tok_coord;

	tok_coord = ft_makevec();///*(m + i) + j)
	i = 0;
	while (i < token->piece_x)
	{
		j = 0;
		while (j < token->piece_y)
		{
			if (piece[i][j] == '*')
				ft_vec_push_back(tok_coord, i, j);
			j++;
		}
		i++;
	}
	return (tok_coord);
}

void		del_arr(char ***arr)
{
	int i;

	i = 0;
	if (!*arr || !**arr)
		return ;
	while (*((*arr) + i))
		free(*((*arr) + i++));
	free(*arr);
}

t_piece		*read_token(void)
{
	char 	*line;
	int 	i;
	char	**piece;
	t_piece	*token;

	token = (t_piece *)ft_memalloc(sizeof(t_piece));
	get_next_line(0, &line);
	line = ft_strchr(line, ' ');
	token->piece_x = ft_atoi(line);
	line = ft_strchr(++line, ' ');
	token->piece_y = ft_atoi(line);
	if(!(piece = (char **)ft_memalloc(token->piece_x + 1)))
		return (NULL);//todo
	i = 0;
	while (i < token->piece_x)
		if (!(*(piece + i++) = (char *)ft_memalloc(token->piece_y + 1)))
			return (NULL); //todo
	*(piece + i) = NULL;
	i = 0;
	while (*(piece + i))
	{
		get_next_line(0, &line);
		*(piece + i) = ft_strcpy(*(piece + i), line);
		i++;
	}
	token->token = create_coord_token(piece, token);
	del_arr((&piece));
	return (token);
}
