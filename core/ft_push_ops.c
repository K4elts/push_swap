/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:11:07 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/30 20:31:06 by jgilaber         ###   ########.fr       */
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
	t_stack_node	*tmp;

	if (!operations_data || !operations_data->b
		|| !*operations_data->b || !(*operations_data->b)->top)
		return ;
	tmp = (*operations_data->b)->top;
	(*operations_data->b)->top = tmp->next;
	if ((*operations_data->b)->top)
		(*operations_data->b)->top->prev = NULL;

	tmp->prev = NULL;
	tmp->next = (*operations_data->a)->top;
	if ((*operations_data->a)->top)
		(*operations_data->a)->top->prev = tmp;
	(*operations_data->a)->top = tmp;

	(*operations_data->a)->size++;
	(*operations_data->b)->size--;
	operations_data->operations_count[OP_PA]++;
	operations_data->operations_count[OP_TOTAL]++;
	ft_putendl_fd("pa", 1);
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
	t_stack_node	*tmp;

	if (!(**operations_data->a).top)
		return ;
	tmp = (*operations_data->a)->top;

	(*operations_data->a)->top = tmp->next;
	if ((*operations_data->a)->top)
		(*operations_data->a)->top->prev = NULL;

	tmp->next = (*operations_data->b)->top;
	tmp->prev = NULL;
	if ((*operations_data->b)->top)
		(*operations_data->b)->top->prev = tmp;
	(*operations_data->b)->top = tmp;

	(*operations_data->a)->size--;
	(*operations_data->b)->size++;
	operations_data->operations_count[OP_PB]++;
	operations_data->operations_count[OP_TOTAL]++;
	ft_putendl_fd("pb", 1);
}
