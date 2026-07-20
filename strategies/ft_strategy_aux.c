/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:20 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/17 19:08:57 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "strategy.h"

/// @brief Finds the position on the stack of the lowest number
/// @param a stack_a
/// @param min Lowest number on the stack
/// @return Position on the stack of the lowest number
/// SUJETO A REVISION POR ANDRES.
int	find_pos(t_stack **a, int min)
{
	t_stack_node	*temp_stack;
	int				pos;

	if (!a || !(*a)->top)
		return (-1);
	temp_stack = (*a)->top;
	pos = 0;
	while (temp_stack)
	{
		if (temp_stack->index == min)
			return (pos);
		pos++;
		temp_stack = temp_stack->next;
	}
	return (-1);
}
