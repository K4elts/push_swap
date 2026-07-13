/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:11:07 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/13 18:34:42 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

void	pb(t_stack **a, t_stack **b)
{
	t_stack_node	*stack_a_top_node_tmp;

	if (!b || !(*b)->top)
		return ;
	stack_a_top_node_tmp = (*a)->top;
	(*a)->top = (*a)->top->next;
	(*a)->top->prev = NULL;
	stack_a_top_node_tmp->next = (*b)->top;
	(*b)->top->prev = stack_a_top_node_tmp;
	(*b)->top = stack_a_top_node_tmp;
	(*b)->size--;
	(*a)->size++;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack_node	*stack_b_top_node_tmp;

	if (!a || !(*a)->top)
		return ;
	stack_b_top_node_tmp = (*b)->top;
	(*b)->top = (*b)->top->next;
	(*b)->top->prev = NULL;
	stack_b_top_node_tmp->next = (*a)->top;
	(*a)->top->prev = stack_b_top_node_tmp;
	(*a)->top = stack_b_top_node_tmp;
	(*a)->size--;
	(*b)->size++;
}
