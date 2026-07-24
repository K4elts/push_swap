/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:11:47 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/22 19:55:33 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that rotate to the top of the stack_s
/// all the elements 1 position, so the first element becomes the last.
/// @authors jgilaber & aliao-tr
/// @param s stack_s
/// @return Nothing
static void	ft_do_rotate_op(t_stack **s)
{
	t_stack_node	*first_stack_node_tmp;
	t_stack_node	*last_stack_node_tmp;

	if ((*s)->size < 2)
		return ;
	first_stack_node_tmp = (*s)->top;

	(*s)->top = (*s)->top->next;
	(*s)->top->prev = NULL;
	last_stack_node_tmp = ft_stack_last(*s);

	first_stack_node_tmp->prev = last_stack_node_tmp;
	first_stack_node_tmp->next = NULL;

	last_stack_node_tmp->next = first_stack_node_tmp;
	ft_stack_remove_node(first_stack_node_tmp);
}

/// @brief Function that rotate to the top of the stack_a
/// all the elements 1 position.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	ra(t_stack **a, int *operations_count)
{
	ft_do_rotate_op(a);
	operations_count[OP_RA]++;
	operations_count[OP_TOTAL]++;
}

/// @brief Function that rotate to the top of the stack_b
/// all the elements 1 position.
/// @authors jgilaber & aliao-tr
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	rb(t_stack **b, int *operations_count)
{
	ft_do_rotate_op(b);
	operations_count[OP_RB]++;
	operations_count[OP_TOTAL]++;
}

/// @brief Function that do ra & rb operations
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @param operations_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	rr(t_stack **a, t_stack **b, int *operations_count)
{
	ra(a, operations_count);//¿ra(&a);?
	rb(b, operations_count);//¿rb(&b);?
	operations_count[OP_RR]++;
	operations_count[OP_RA]--;
	operations_count[OP_RB]--;
	operations_count[OP_TOTAL]--;
}
