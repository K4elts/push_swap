/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:49:24 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/21 20:24:32 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that checks if there is a chunk
/// between start and end in medium strategy
/// @param a stack_a
/// @param start 
/// @param end 
/// @return Int -> If there is a chunk between start and end
static int	ft_check_if_stack_has_a_chunk_on_a_range(
	t_stack *s, size_t start, size_t end)
{
	t_stack_node	*tmp;

	tmp = s->top;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/// @brief Function that does medium strategy operations
// HAY QUE DEJAR AL FINAL DE B SIEMPRE EL VALOR MAS PEQUEÑO
/// @param a stack_a
/// @param b stack_b
/// @param ops_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	ft_do_medium_strategy_operations(
	t_push_swap_ops_data *ops_data, int chunk_size)
{
	size_t	range_start;
	size_t	range_end;
	size_t	total_size;

	total_size = (*ops_data->a)->size;
	range_start = 0;
	while (range_start < total_size)
	{
		range_end = range_start + chunk_size - 1;
		if (range_end >= total_size)
			range_end = total_size - 1;
		while (ft_check_if_stack_has_a_chunk_on_a_range(
				*ops_data->a, range_start, range_end))
		{
			if ((*ops_data->a)->top->index >= range_start
				&& (*ops_data->a)->top->index <= range_end)
			{
				pb(ops_data);
				if ((*ops_data->b)->top->index < range_start + chunk_size / 2)
					rb(ops_data->b, ops_data->operations_count, 1);
			}
			else
				ra(ops_data->a, ops_data->operations_count, 1);
		}
		range_start += chunk_size;
	}
}

/// @brief Function that reconstructs stack_a from stack_b in medium strategy
//esta funcion se tiene que ejecutar en bucle cuando ->
/// @param a stack_a
/// @param b stack_b
/// @param ops_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
void	ft_do_medium_strategy_reconstruction(
	t_push_swap_ops_data *ops_data)
{
	size_t	moves;
	size_t	max_pos;

	while ((*ops_data->b)->top)
	{
		max_pos = ft_get_max_stack_node_pos(*ops_data->b);
		if (max_pos <= (*ops_data->b)->size / 2)
		{
			moves = max_pos;
			while (moves--)
				rb(ops_data->b, ops_data->operations_count, 1);
		}
		else
		{
			moves = (*ops_data->b)->size - max_pos;
			while (moves--)
				rrb(ops_data->b, ops_data->operations_count, 1);
		}
		pa(ops_data);
	}
}
