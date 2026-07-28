/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:11:23 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/27 18:42:56 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that swap the first and the second element of stack_s.
/// @authors jgilaber & aliao-tr
/// @param s stack_s
/// @return Nothing
static void	ft_do_swap_op(t_stack **stack)
{
	t_stack_node	*first_stack_node_tmp;

	if ((*stack)->size < 2)
		return ;
	first_stack_node_tmp = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	(*stack)->top->prev = NULL;
	first_stack_node_tmp->prev = (*stack)->top;
	first_stack_node_tmp->next = (*stack)->top->next;
	(*stack)->top->next->prev = first_stack_node_tmp;
	(*stack)->top->next = first_stack_node_tmp;
	ft_stack_remove_node(first_stack_node_tmp);
}

/// @brief Function that swap the first and the second element of stack_a.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	sa(t_stack **a, int *operations_count, int show_op)
{
	ft_do_swap_op(a);
	operations_count[OP_SA]++;
	operations_count[OP_TOTAL]++;
	if (show_op)
		write(1, "sa", 2);
}

/// @brief Function that swap the first and the second element of stack_b.
/// @authors jgilaber & aliao-tr
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	sb(t_stack **b, int *operations_count, int show_op)
{
	ft_do_swap_op(b);
	operations_count[OP_SB]++;
	operations_count[OP_TOTAL]++;
	if (show_op)
		write(1, "sb", 2);
}

/// @brief Function that do sa & sb operations
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	ss(t_push_swap_ops_data *operations_data)
{
	sa(operations_data->a, operations_data->operations_count, 0);
	sb(operations_data->b, operations_data->operations_count, 0);
	operations_data->operations_count[OP_SS]++;
	operations_data->operations_count[OP_SA]--;
	operations_data->operations_count[OP_SB]--;
	operations_data->operations_count[OP_TOTAL]--;
	write(1, "ss", 2);
}
