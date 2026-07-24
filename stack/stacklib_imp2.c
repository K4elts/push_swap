/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklib_imp2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:45:33 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/13 21:11:07 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacklib.h"

/// @brief Function that update all stack_node index
/// @authors jgilaber & aliao-tr
/// @param s stack_s
/// @return Nothing
void	ft_stack_update_index(t_stack **s)
{
	size_t	index;

	if (!s)
		return ;
	index = 0;
	while ((*s)->top)
	{
		(*s)->top->index = index++;
		(*s)->top = (*s)->top->next;
	}
}

/// @brief Finds the lowest number on the stack
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @return min - The lowest number on the stack
/// SUJETO A REVISION POR ANDRES.
int	ft_get_min_stack_node_index(t_stack **stack)
{
	int		min_stack_node_index;
	t_stack	**temp_stack;

	if (!stack || !(*stack)->top)
		return (-1);
	temp_stack = stack;
	min_stack_node_index = (*temp_stack)->top->index;
	while ((*temp_stack)->top)
	{
		if ((*temp_stack)->top->index < min_stack_node_index)
			min_stack_node_index = (*temp_stack)->top->index;
		(*temp_stack)->top = (*temp_stack)->top->next;
	}
	return (min_stack_node_index);
}

/// @brief Finds the position on the stack of the lowest number
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param min Lowest number on the stack
/// @return Position on the stack of the lowest number
/// SUJETO A REVISION POR ANDRES.
int	ft_get_min_stack_node_position(t_stack **stack, int min_stack_node_index)
{
	t_stack_node	*temp_stack;
	int				pos;

	if (!stack || !(*stack)->top)
		return (-1);
	temp_stack = (*stack)->top;
	pos = 0;
	while (temp_stack)
	{
		if (temp_stack->index == min_stack_node_index)
			return (pos);
		pos++;
		temp_stack = temp_stack->next;
	}
	return (-1);
}
