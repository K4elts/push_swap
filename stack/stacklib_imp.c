/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklib_imp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:45:33 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/13 21:11:07 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacklib.h"
#include <stdio.h>

/// @brief 
/// @param numbres 
/// @param strategy_useg 
/// @return t_stack A new stack with ¿?
t_stack	*ft_new_stack(int *numbers, int strategy_argv, int numbers_size)
{
	size_t			stack_size;
	int				stack_node_index;
	t_stack			*new_stack;
	t_stack_node	*temp_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	stack_size = 0;
	while (stack_size < (size_t)numbers_size)
	{
		//stack_node_index = ft_get_stack_node_index_from_value(
				//&numbers[stack_size], numbers[stack_size], numbers_size);
		stack_node_index = ft_get_stack_node_index_from_value(
				numbers, numbers[stack_size], numbers_size);
		temp_stack = ft_new_stack_node(numbers[stack_size], stack_node_index);
		if (!temp_stack)
		{
			ft_stack_clear(&new_stack);
			return (NULL);
		}
		ft_stack_push(&new_stack, temp_stack);
		//numbers++;
		stack_size++;
	}
	new_stack->size = stack_size;
	new_stack->strategy_used = strategy_argv;
	return (new_stack);
}

/// @brief Function that calculate the index of tne recived value max_value
/// @param numbers 
/// @param max_value El valor sobre el que tenemos que cacular el index.
/// @return 
int	ft_get_stack_node_index_from_value(int *numbers, int max_value, int numbers_size)
{
	int	numbers_index;
	int	stack_node_min_count_index;
	numbers_index = 0;
	stack_node_min_count_index = 0;
	while (numbers_index < numbers_size)//while (numbers[numbers_index]) //numbers_index < max_size
	{
		if (numbers[numbers_index] < max_value)
			stack_node_min_count_index++;
		numbers_index++;
	}
	return (stack_node_min_count_index);
}

/// @brief Function that creates a new node of type t_stack_node.
/// @authors jgilaber & aliao-tr
/// @param data The data of the new node.
/// @return t_stack_node -> The new stack_node created. 
t_stack_node	*ft_new_stack_node(int data, int index)
{
	t_stack_node	*stack_node;

	stack_node = malloc(sizeof(t_stack_node));
	if (!stack_node)
		return (NULL);
	stack_node->data = data;
	stack_node->index = index;
	stack_node->prev = NULL;
	stack_node->next = NULL;
	return (stack_node);
}

/// @brief Function that returns the last node of a stack.
/// @authors jgilaber & aliao-tr
/// @param stack The stack to get the last node from.
/// @return t_stack_node -> The last node of the stack.
t_stack_node	*ft_stack_last(t_stack *stack)
{
	t_stack_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	while (current->next)
		current = current->next;
	return (current);
}

/// @brief Function that pushes a new node to the top of a stack.
/// @authors jgilaber & aliao-tr
/// @param stack The stack to push to.
/// @param  new The new node to push.
/// @return Nothing
void	ft_stack_push(t_stack **stack, t_stack_node *new)
{
	t_stack_node	*tmp_stack_node;

	if (!(*stack)->top)
	{
		(*stack)->top = new;
		return ;
	}
	tmp_stack_node = (*stack)->top;
	new->next = tmp_stack_node;
	tmp_stack_node->prev = new;
	(*stack)->top = new;
}

