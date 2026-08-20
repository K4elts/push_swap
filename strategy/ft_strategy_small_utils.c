/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_small_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:33:52 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/08/20 17:59:34 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_get_index_pos
static int	get_index_pos(t_push_swap_ops_data *ops_data, size_t index)
{
	int				pos;
	t_stack_node	*node;

	node = (*ops_data->a)->top;
	pos = 0;
	while (node)
	{
		if (node->index == index)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

void	move_index_to_top(t_push_swap_ops_data *operations_data, size_t index)
{
	while ((*operations_data->a)->top->index != index)
	{
		if (get_index_pos(operations_data, index)
			<= (*operations_data->a)->size / 2)
			ra(operations_data->a, operations_data->operations_count, 1);
		else
			rra(operations_data->a, operations_data->operations_count, 1);
	}
}
