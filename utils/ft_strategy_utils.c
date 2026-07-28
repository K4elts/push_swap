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
/// @param a 
/// @param start 
/// @param end 
/// @return Int -> If there is a chunk between start and end
static int	ft_check_if_stack_has_a_chunk_on_a_range(
	t_stack *a, int start, int end)
{
	t_stack_node	*tmp;

	tmp = a->top;
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
/// @param ops_count 
void	ft_do_medium_strategy_operations(
	t_push_swap_ops_data *ops_data, int chunk_size)
{
	int	chunk_range_start;
	int	chunk_range_end;

	chunk_range_start = 0;
	while (chunk_range_start < (*ops_data->a)->size)
	{
		chunk_range_end = chunk_range_start + chunk_size - 1;
		if (chunk_range_end >= (*ops_data->a)->size)
			chunk_range_end = (*ops_data->a)->size - 1;
		while (ft_check_if_stack_has_a_chunk_on_a_range(
				*ops_data->a, chunk_range_start, chunk_range_end))
		{
			if ((*ops_data->a)->top->index >= chunk_range_start
				&& (*ops_data->a)->top->index <= chunk_range_end)
			{
				pb(ops_data);
				if ((*ops_data->a)->top->index
					<= chunk_range_start + chunk_size / 2)
					rb(ops_data->b, ops_data->operations_count, 1);
			}
			else
				ra(ops_data->a, ops_data->operations_count, 1);
		}
		chunk_range_start += chunk_size;
	}
}

/// @brief Function that reconstructs stack_a from stack_b in medium strategy
//esta funcion se tiene que ejecutar en bucle cuando ->
///mirar en chatgpt si es mientras siga habiendo elementos en stack_b
/// @param a stack_a
/// @param b stack_b
/// @param ops_count 
void	ft_do_medium_strategy_reconstruction(
	t_push_swap_ops_data *ops_data)
{
	int	max_pos;

	while ((*ops_data->b)->top)
	{
		max_pos = ft_get_max_stack_node_pos(*ops_data->b);
		if (max_pos <= (*ops_data->b)->size / 2)
			while (max_pos--)
				rb(ops_data->b, ops_data->operations_count, 1);
		else
		{
			max_pos = (*ops_data->b)->size - max_pos;
			while (max_pos--)
				rrb(ops_data->b, ops_data->operations_count, 1);
		}
		pa(ops_data);
	}
}
