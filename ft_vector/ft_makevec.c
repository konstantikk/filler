//
//  ft_makevec.c
//  ft_vector
//
//  Created by Вера on 07/04/2019.
//  Copyright © 2019 Вера. All rights reserved.
//

#include "ft_vector.h"

t_vec	*ft_makevec()
{
	t_vec *r;
	
	if (!(r = (t_vec *)malloc(sizeof(t_vec))))
		return (0);
	r->cap = 10;
	r->len = 0;
	if (!(r->x = ft_memalloc(sizeof(int) * 10)))
		return (0);
	if (!(r->y = ft_memalloc(sizeof(int) * 10)))
		return (0);
	return (r);
}

void	ft_vec_pop_front(t_vec	*vec)
{
	int	*new_x;
	int	*new_y;
	int i;
	
	i = 0;
	if (!vec)
		return ;
	vec->len--;
	printf("len: %zu\n", vec->len);
	new_x = ft_memalloc(vec->len);
	new_y = ft_memalloc(vec->len);
	while (i < vec->len)
	{
		new_x[i] = vec->x[i + 1];
		new_y[i] = vec->y[i + 1];
		i++;
	}
	free(vec->x);
	free(vec->y);
	vec->x = new_x;
	vec->y = new_y;
}

void	ft_vec_push_back(t_vec	*vec, int x, int y)
{
	int *new_x;
	int *new_y;
	
	
	if (!vec)
		return ;
	if (vec->len + 1 >= vec->cap)
	{
		while (vec->len + 1 >= vec->cap)
			vec->cap *= 2;
		new_x = ft_memalloc(vec->cap);
		new_y = ft_memalloc(vec->cap);
		ft_memcpy(new_x, vec->x, vec->len);
		ft_memcpy(new_y, vec->y, vec->len);
		new_x[vec->len] = x;
		new_y[vec->len++] = y;
		free(vec->x);
		free(vec->y);
		vec->x = new_x;
		vec->y = new_y;
	}
	else
	{
		vec->x[vec->len] = x;
		vec->y[vec->len++] = y;
	}
}

void	ft_free_vec(t_vec **vec)
{
	if (*vec && (*vec)->x && (*vec)->y)
	{
		free((*vec)->x);
		free((*vec)->y);
		(*vec)->x = 0;
		(*vec)->y = 0;
	}
	if (*vec)
	{
		free(*vec);
		*vec = 0;
	}
}
