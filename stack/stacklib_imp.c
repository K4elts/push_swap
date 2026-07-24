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

/// @brief Function that creates a new node of type t_stack_node.
/// @authors jgilaber & aliao-tr
/// @param data The data of the new node.
/// @return t_stack_node -> The new stack_node created. 
t_stack_node	*ft_stack_new(int data, int index)
{
	t_stack_node	*stack_node;

	stack_node = malloc(sizeof(t_stack_node));
	if (!stack_node)
		return (NULL);
	stack_node->prev = NULL;
	stack_node->next = NULL;
	stack_node->data = data;
	stack_node->index = index;// siempre sera size-1 en la primera asignacion.
	return (stack_node);
}

/// @brief Function that returns the last node of a stack.
/// @authors jgilaber & aliao-tr
/// @param stack The stack to get the last node from.
/// @return t_stack_node -> The last node of the stack.
t_stack_node	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->top->next)
		stack->top = stack->top->next;
	return (stack->top);
}

/// @brief Function that pushes a new node to the top of a stack.
/// @authors jgilaber & aliao-tr
/// @param stack The stack to push to.
/// @param  new The new node to push.
/// @return Nothing
void	ft_stack_push(t_stack **stack, t_stack_node *new)
{
	t_stack_node	*tmp_stack_node;

	tmp_stack_node = (*stack)->top;
	new->next = tmp_stack_node;
	tmp_stack_node->prev = new;
	(*stack)->top = new;
}

/// @brief Function that removes a node from a stack.
/// @authors jgilaber & aliao-tr
/// @param stack_node The stack node to remove.
/// @return Nothing
void	ft_stack_remove_node(t_stack_node *stack_node)
{
	if (!stack_node)
		return ;
	//free(stack_node->data);//no se puede ya que data nno es int* sino int a secas.
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
		ft_stack_remove_node((*stack)->top);
		(*stack)->top = tmp_stack_node;
	}
}
