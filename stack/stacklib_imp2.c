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

/// @brief Function that removes a node from a stack.
/// @authors jgilaber & aliao-tr
/// @param stack_node The stack node to remove.
/// @return Nothing
void	ft_stack_remove_node(t_stack_node *stack_node)
{
	if (!stack_node)
		return ;
	free(stack_node);
}

/// @brief Function that removes all nodes from a stack.
/// @authors jgilaber & aliao-tr
/// @param stack The stack to remove the node from.
/// @return Nothing
void	ft_stack_clear(t_stack **stack)
{
	t_stack_node	*tmp_stack_node;

	if (!stack)
		return ;
	while (*stack != NULL)
	{
		tmp_stack_node = (*stack)->top->next;
		free((*stack)->top);
		(*stack)->top = tmp_stack_node;
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
int	ft_get_min_stack_node_pos(t_stack **stack, int min_stack_node_index)
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

/// @brief Function that ¿?
/// @param b stack_b
/// @return int The psoition of ¿?
int	ft_get_max_stack_node_pos(t_stack *b)
{
	int				max;
	int				pos;
	int				i;
	t_stack_node	*tmp;

	i = 0;
	pos = 0;
	max = -1;
	tmp = b->top;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}
