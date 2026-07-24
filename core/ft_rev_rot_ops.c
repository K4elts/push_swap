/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rot_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:12:12 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/22 19:55:23 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that rotate to the bottom of the stack_s
/// all the elements 1 position, so the last element becomes the first.
/// @authors jgilaber & aliao-tr
/// @param s stack_s
/// @return Nothing
static void	ft_do_reverse_rotate_op(t_stack **s)
{
	t_stack_node	*first_stack_node_tmp;
	t_stack_node	*last_stack_node_tmp;

	if ((*s)->size < 2)
		return ;
	first_stack_node_tmp = (*s)->top;
	last_stack_node_tmp = ft_stack_last(*s);

	last_stack_node_tmp->prev->next = NULL;
	last_stack_node_tmp->prev = NULL;
	last_stack_node_tmp->next = first_stack_node_tmp;

	first_stack_node_tmp->prev = last_stack_node_tmp;
	(*s)->top = last_stack_node_tmp;

	ft_stack_remove_node(first_stack_node_tmp);
	ft_stack_remove_node(last_stack_node_tmp);
}

/// @brief Function that rotate to the bottom of the stack_a
/// all the elements 1 position.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	rra(t_stack **a, int *operations_count)
{
	ft_do_reverse_rotate_op(a);
	operations_count[OP_RRA]++;
	operations_count[OP_TOTAL]++;
}

/// @brief Function that rotate to the bottom of the stack_b
/// all the elements 1 position.
/// @authors jgilaber & aliao-tr
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	rrb(t_stack **b, int *operations_count)
{
	ft_do_reverse_rotate_op(b);
	operations_count[OP_RRB]++;
	operations_count[OP_TOTAL]++;
}

/// @brief Function that do rra & rrb operations
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	rrr(t_stack **a, t_stack **b, int *operations_count)
{
	rra(a, operations_count);//¿rra(&a);?
	rrb(b, operations_count);//¿rrb(&b);?
	operations_count[OP_RRR]++;
	operations_count[OP_RRA]--;
	operations_count[OP_RRB]--;
	operations_count[OP_TOTAL]--;
}
