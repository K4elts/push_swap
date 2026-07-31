/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_strategy_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:33:52 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/31 17:04:40 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_index_pos(t_push_swap_ops_data *operations_data, size_t index)
{
	size_t			pos;
	t_stack_node	*node;

	node = (*operations_data->a)->top;
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

void	ft_sort_small(t_push_swap_ops_data *operations_data)
{
	int	size;

	size = (*operations_data->a)->size;
	if (size == 2)//y disorder sea 100% o 1
		sort_two(operations_data);
	else if (size == 3)
		sort_three(operations_data);
	else if (size == 4)
		sort_four(operations_data);
	else if (size == 5)
		sort_five(operations_data);
}
