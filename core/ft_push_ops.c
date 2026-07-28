/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:11:07 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/27 18:39:27 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that take the first element of stack_b
/// and push it to the top of stack_a.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	pa(t_push_swap_ops_data *operations_data)
{
	t_stack_node	*stack_b_top_node_tmp;

	if (!operations_data || !(*operations_data->a)->top)
		return ;
	stack_b_top_node_tmp = (*operations_data->b)->top;
	(*operations_data->b)->top = (*operations_data->b)->top->next;
	(*operations_data->b)->top->prev = NULL;
	stack_b_top_node_tmp->next = (*operations_data->a)->top;
	(*operations_data->a)->top->prev = stack_b_top_node_tmp;
	(*operations_data->a)->top = stack_b_top_node_tmp;
	(*operations_data->a)->size++;
	(*operations_data->b)->size--;
	ft_stack_remove_node(stack_b_top_node_tmp);
	operations_data->operations_count[OP_PA]++;
	operations_data->operations_count[OP_TOTAL]++;
	write(1, "pa", 2);
}

/// @brief Function that take the first element of stack_a
/// and push it to the top of stack_b.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	pb(t_push_swap_ops_data *operations_data)
{
	t_stack_node	*stack_a_top_node_tmp;

	if (!operations_data || !(*operations_data->b)->top)
		return ;
	stack_a_top_node_tmp = (*operations_data->a)->top;
	(*operations_data->a)->top = (*operations_data->a)->top->next;
	(*operations_data->a)->top->prev = NULL;
	stack_a_top_node_tmp->next = (*operations_data->b)->top;
	(*operations_data->b)->top->prev = stack_a_top_node_tmp;
	(*operations_data->b)->top = stack_a_top_node_tmp;
	(*operations_data->a)->size--;
	(*operations_data->b)->size++;
	ft_stack_remove_node(stack_a_top_node_tmp);
	operations_data->operations_count[OP_PB]++;
	operations_data->operations_count[OP_TOTAL]++;
	write(1, "pb", 2);
}
