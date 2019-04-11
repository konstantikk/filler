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

t_filler	ft_read(t_filler fill, char **map)
{
	char		*line;
	char 		*buff;

	get_next_line(0, &buff);
	line = buff;
	free(buff);
	//ft_putendl_fd(line,fill.fd); ///todo  del
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
	//ft_putendl_fd(line,fill.fd); ///todo  del
	free(line);
	fill.map = create_map(&fill, map);
	return (fill);
}

t_piece		*read_token(t_filler *fill)
{
	char 	*line;
	int 	i;
	char	**piece;
	t_piece	*token;
	char	*buff;

	token = (t_piece *)ft_memalloc(sizeof(t_piece));
	get_next_line(0, &buff);
	line  = buff;
	//ft_putendl_fd(line,fill->fd); /// todo  del
	line = ft_strchr(line, ' ');
	token->piece_x = ft_atoi(line);
	line = ft_strchr(++line, ' ');
	token->piece_y = ft_atoi(line);
	free(buff);
	if(!(piece = (char **)malloc(token->piece_x + 1)))
		return (NULL);//todo
	i = -1;
	while (i < token->piece_x)
		if (!(*(piece + ++i) = (char *)malloc(token->piece_y + 1)))
			return (NULL); //todo
	*(piece + i) = NULL;
	i = -1;
	while (++i < token->piece_x ) ///(*(piece + i))
	{
		get_next_line(0, &line);
		//ft_putendl_fd(line,fill->fd); /// todo  del
		*(piece + i) = ft_strcpy(*(piece + i), line);
		free(line);
	}
	token->token = create_coord_token(piece, token);
	return (token);
}
