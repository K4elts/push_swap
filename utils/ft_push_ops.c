/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:11:07 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/17 18:54:42 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that take the first element of stack_b
/// and push it to the top of stack_a.
/// @param a stack_a
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	pa(t_stack **a, t_stack **b, int *operations_count)
{
	t_stack_node	*stack_b_top_node_tmp;

	if (!a || !(*a)->top)
		return ;
	stack_b_top_node_tmp = (*b)->top;

	(*b)->top = (*b)->top->next;
	(*b)->top->prev = NULL;

	stack_b_top_node_tmp->next = (*a)->top;
	(*a)->top->prev = stack_b_top_node_tmp;
	(*a)->top = stack_b_top_node_tmp;

	(*a)->size++;
	(*b)->size--;

	ft_stack_remove_node(stack_b_top_node_tmp);
	operations_count[OP_PA]++;
	operations_count[OP_TOTAL]++;
}

/// @brief Function that take the first element of stack_a
/// and push it to the top of stack_b.
/// @param a stack_a
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	pb(t_stack **a, t_stack **b, int *operations_count)
{
	t_stack_node	*stack_a_top_node_tmp;

	if (!b || !(*b)->top)
		return ;
	stack_a_top_node_tmp = (*a)->top;

	(*a)->top = (*a)->top->next;
	(*a)->top->prev = NULL;

	stack_a_top_node_tmp->next = (*b)->top;
	(*b)->top->prev = stack_a_top_node_tmp;
	(*b)->top = stack_a_top_node_tmp;

	(*a)->size--;
	(*b)->size++;

	ft_stack_remove_node(stack_a_top_node_tmp);
	operations_count[OP_PB]++;
	operations_count[OP_TOTAL]++;
}
