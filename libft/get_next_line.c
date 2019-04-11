/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:21:12 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/18 00:04:59 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*newlst(size_t fd)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	new->content = (void *)ft_strdup("");
	new->content_size = fd;
	if (!(new->content))
		return (NULL);
	return (new);
}

static t_list	*getcurlst(int fd, t_list **l)
{
	t_list	*temp;

	temp = *l;
	while (temp)
	{
		if (temp->content_size == (unsigned int)fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = newlst((size_t)fd)))
		return (NULL);
	ft_lstadd(l, temp);
	temp = *l;
	return (temp);
}

static int		node_solver(t_list *src, char **line)
{
	char	*temp;

	if (src->content && (temp = ft_strchr((char *)src->content, '\n')))
	{
		if (!(*line = ft_strsub(src->content, 0, temp - (char *)src->content)))
			return (-1);
		temp++;
		temp = ft_strdup(temp);
		free(src->content);
		src->content = temp;
		return (1);
	}
	return (0);
}

static int		end_it(char **line, t_list *src)
{
	if (src->content)
		if (ft_strlen((char *)src->content))
		{
			if (!(*line = ft_strdup((char *)src->content)))
				return (-1);
			else
			{
				if (line[0][ft_strlen(*line) - 1] == '\n')
					line[0][ft_strlen(*line) - 1] = '\0';
				free(src->content);
				src->content = NULL;
				return (1);
			}
		}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*l;
	t_list			*src;
	char			buff[BUFF_SIZE + 1];
	int				place;
	char			*temp;

	temp = NULL;
	if (fd < 0 || !line || (read(fd, buff, 0) < 0)
			|| !(src = getcurlst(fd, &l)))
		return (-1);
	if ((place = node_solver(src, line)))
		return (place);
	while ((place = read(fd, buff, BUFF_SIZE)))
	{
		buff[place] = '\0';
		if (!(temp = ft_strjoin((char *)src->content, buff)))
			return (-1);
		ft_memdel(&(src->content));
		src->content = (void *)temp;
		if ((place = node_solver(src, line)))
			return (place);
	}
	return (end_it(line, src));
}
