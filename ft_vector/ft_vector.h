//
//  ft_vector.h
//  ft_vector
//
//  Created by Вера on 07/04/2019.
//  Copyright © 2019 Вера. All rights reserved.
//

#ifndef ft_vector_h
#define ft_vector_h
#include "libft/libft.h"
#include <stdio.h>

struct		s_vec
{
	int		*x;
	int		*y;
	size_t	cap;
	size_t	len;
} typedef	t_vec;

t_vec	*ft_makevec(void);
void	ft_vec_push_back(t_vec	*vec, int x, int y);
void	ft_free_vec(t_vec **vec);
void	ft_vec_pop_front(t_vec	*vec);
#endif /* ft_vector_h */
