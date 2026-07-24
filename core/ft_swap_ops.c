/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:11:23 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/22 19:55:40 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that swap the first and the second element of stack_s.
/// @authors jgilaber & aliao-tr
/// @param s stack_s
/// @return Nothing
static void	ft_do_swap_op(t_stack **s)
{
	t_stack_node	*first_stack_node_tmp;

	if ((*s)->size < 2)
		return ;
	first_stack_node_tmp = (*s)->top;

	(*s)->top = (*s)->top->next;
	(*s)->top->prev = NULL;

	first_stack_node_tmp->prev = (*s)->top;
	first_stack_node_tmp->next = (*s)->top->next;

	(*s)->top->next->prev = first_stack_node_tmp;
	(*s)->top->next = first_stack_node_tmp;
	ft_stack_remove_node(first_stack_node_tmp);
}

/// @brief Function that swap the first and the second element of stack_a.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	sa(t_stack **a, int *operations_count)
{
	ft_do_swap_op(a);
	operations_count[OP_SA]++;
	operations_count[OP_TOTAL]++;
}

/// @brief Function that swap the first and the second element of stack_b.
/// @authors jgilaber & aliao-tr
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	sb(t_stack **b, int *operations_count)
{
	ft_do_swap_op(b);
	operations_count[OP_SB]++;
	operations_count[OP_TOTAL]++;
}

/// @brief Function that do sa & sb operations
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	ss(t_stack **a, t_stack **b, int *operations_count)
{
	sa(a, operations_count);//¿sa(&a);?
	sb(b, operations_count);//¿sb(&b);?
	operations_count[OP_SS]++;
	operations_count[OP_SA]--;
	operations_count[OP_SB]--;
	operations_count[OP_TOTAL]--;
}
