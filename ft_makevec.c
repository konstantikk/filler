/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:12:16 by jziemann          #+#    #+#             */
/*   Updated: 2019/04/03 20:12:16 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_func.h"

t_vec	*ft_makevec(void)
{
	t_vec *r;

	if (!(r = (t_vec *)malloc(sizeof(t_vec))))
		return (0);
	r->cap = 10;
	r->len = 0;
	if (!(r->x = (int *)malloc(sizeof(int) * 10)))
		return (0);
	if (!(r->y = (int *)malloc(sizeof(int) * 10)))
		return (0);
	r->start_x = r->x;
	r->start_y = r->y;
	return (r);
}

void	ft_vec_pop_front(t_vec *vec)
{
	if (!vec || !vec->len)
		return ;
	vec->x++;
	vec->y++;
	vec->cap--;
	vec->len--;
}

void	help_push_back(t_vec *vec, int x, int y)
{
	int	*new_x;
	int	*new_y;
	int	i;

	i = -1;
	while (vec->len >= vec->cap)
		vec->cap *= 2;
	new_x = malloc(vec->cap * sizeof(int));
	new_y = malloc(vec->cap * sizeof(int));
	while (++i < vec->len)
		new_x[i] = vec->x[i];
	i = -1;
	while (++i < vec->len)
		new_y[i] = vec->y[i];
	new_x[vec->len] = x;
	new_y[vec->len++] = y;
	free(vec->start_x);
	free(vec->start_y);
	vec->x = new_x;
	vec->y = new_y;
	vec->start_x = vec->x;
	vec->start_y = vec->y;
}

void	ft_vec_push_back(t_vec *vec, int x, int y)
{
	if (!vec)
		return ;
	if (vec->len + 1 > vec->cap)
		help_push_back(vec, x, y);
	else
	{
		vec->x[vec->len] = x;
		vec->y[vec->len++] = y;
	}
}

void	ft_free_vec(t_vec **vec)
{
	if (*vec && (*vec)->start_x && (*vec)->start_y)
	{
		free((*vec)->start_x);
		free((*vec)->start_y);
		(*vec)->start_x = 0;
		(*vec)->start_y = 0;
	}
	if (*vec)
	{
		free(*vec);
		*vec = 0;
	}
}
