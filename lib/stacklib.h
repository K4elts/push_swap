/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:45:33 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/27 19:25:58 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKLIB_H
# define STACKLIB_H

# include <stddef.h>
# include <stdlib.h>//malloc, free
# include "strategy.h"

typedef struct s_stack_node
{
	int					data;
	int					index;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	size_t			size;
	float			disorder;
	t_strategy_type	strategy_used;
}	t_stack;

t_stack			*ft_new_stack(int *numbres, int strategy_useg);
t_stack_node	*ft_new_stack_node(int data, int index);
t_stack_node	*ft_stack_last(t_stack *stack);
void			ft_stack_push(t_stack **stack, t_stack_node *new);
void			ft_stack_remove_node(t_stack_node *stack);
void			ft_stack_clear(t_stack **stack);
int				ft_get_stack_node_index_from_value(int *numbers, int max_value);
int				ft_get_min_stack_node_index(t_stack **s);
int				ft_get_min_stack_node_pos(t_stack **a,
					int min_stack_node_index);
int				ft_get_max_stack_node_pos(t_stack *b);

#endif