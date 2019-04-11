/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:41:20 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/11 18:41:20 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_func.h"

void		del_arr(void ***arr)
{
	int i;

	i = 0;
	if (!*arr || !**arr)
		return ;
	while (*((*arr) + i))
		free(*((*arr) + i++));
	free(*arr);
}

char 	**create_map(t_filler *fill, char **map)
{
	char	*line;
	int		i;

	if (map == NULL)
	{
		if (!(map = (char **)ft_memalloc(fill->map_x)))
			return (NULL); //todo
		i = 0;
		while (i < fill->map_x)
			if (!(*(map + i++) = (char *)ft_memalloc(fill->map_y)))
				return (NULL); //todo
		*(map + i) = NULL;
		fill->int_map = int_map(*fill);
		fill->int_enemy_map = int_map(*fill);
	}
	i = 0;
	while (*(map + i))
	{
		get_next_line(0, &line);
		free(line);
		//ft_putendl_fd(line,fill->fd); /// todo  del
		line = ft_strchr(line, ' ');
		*(map + i) = ft_strcpy(*(map + i), ++line);
		i++;
	}
	return (map);
}

t_vec		*create_coord_token(char **piece, t_piece *token)////todooo
{
	register int	i;
	register int	j;
	t_vec			*tok_coord;
	const int 		piece_y = token->piece_y;
	const int 		piece_x = token->piece_x;

	tok_coord = ft_makevec();
	i = -1;
	while (++i < piece_x)
	{
		j = -1;
		while (++j < piece_y)
			if (piece[i][j] == '*')
				ft_vec_push_back(tok_coord, i, j);
	}
	del_arr((void ***)(&piece));
	return (tok_coord);
}

int 	**int_map(t_filler fill)
{
	int **arr;
	int i;

	if (!(arr = (int **)ft_memalloc(sizeof(int) * (fill.map_x + 1))))
		return (NULL);
	i = -1;
	while (i < fill.map_x)
		if (!(*(arr + ++i) = (int *)ft_memalloc(sizeof(int)*(fill.map_y + 1))))
			return (NULL); //todo
	*(arr + i) = NULL;
	return (arr);
}