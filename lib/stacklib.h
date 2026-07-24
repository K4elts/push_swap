/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:45:33 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/20 21:45:53 by jgilaber         ###   ########.fr       */
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
	float			disorder;//posible double, revisar pros y contras de uno y otro en este caso. Tiene preferencia lo que devuelve el disorder().
	t_strategy		strategy_arg;
	t_strategy		strategy_used;
}	t_stack;

t_stack_node	*ft_stack_new(int data, int index);
t_stack_node	*ft_stack_last(t_stack *stack);
void			ft_stack_push(t_stack **stack, t_stack_node *new);
void			ft_stack_remove_node(t_stack_node *stack);
void			ft_stack_clear(t_stack **stack);
void			ft_stack_update_index(t_stack **a);
int				ft_get_min_stack_node_index(t_stack **s);
int				ft_get_min_stack_node_position(t_stack **a, int min_stack_node_index);

#endif