/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:42:25 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/28 17:29:57 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_push_swap_ops_data *operations_data)
{
	int	first;
	int	second;
	int	third;

	first = (*operations_data->a)->top->data;
	second = (*operations_data->a)->top->next->data;
	third = (*operations_data->a)->top->next->next->data;
	if (first < second && second < third)
		return ;
	else if (first > second && first < third)
		sa(operations_data->a, operations_data->operations_count, 1);
	else if (first > second && second > third)
	{
		sa(operations_data->a, operations_data->operations_count, 1);
		rra(operations_data->a, operations_data->operations_count, 1);
	}
	else if (first > second && first > third)
		ra(operations_data->a, operations_data->operations_count, 1);
	else if (first < second && first < third)
	{
		sa(operations_data->a, operations_data->operations_count, 1);
		ra(operations_data->a, operations_data->operations_count, 1);
	}
	else
		rra(operations_data->a, operations_data->operations_count, 1);
}

void	sort_four(t_push_swap_ops_data *operations_data)
{
	if ((*operations_data->a)->top->index == 1)
		ra(operations_data->a, operations_data->operations_count, 1);
	else if ((*operations_data->a)->top->index == 2)
	{
		ra(operations_data->a, operations_data->operations_count, 1);
		ra(operations_data->a, operations_data->operations_count, 1);
	}
	else if ((*operations_data->a)->top->index == 3)
		rra(operations_data->a, operations_data->operations_count, 1);
	pb(operations_data);
	sort_three(operations_data);
	pa(operations_data);
}
