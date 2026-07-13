/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_simple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:20 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/13 18:38:45 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Finds the lowest number on the list
/// @param a stack_a
/// @return min - The lowest number on the list
int	find_min(t_stack **a)
{
	int		min;
	t_stack	**temp_stack;

	temp_stack = a;
	if (a == NULL)
		return ;
	min = (*temp_stack)->top->data;
	while ((*temp_stack)->top)
	{
		if ((*temp_stack)->top->data < min)
			min = (*temp_stack)->top->data;
		(*temp_stack)->top = (*temp_stack)->top->next;
	}
	return (min);
}

/// @brief Finds the position on the list of the lowest number
/// @param a stack_a
/// @param min Lowest number on the list
/// @return Position on the list of the lowest number
int	find_pos(t_stack **a, int min)
{
	t_stack	**temp_stack;
	int		pos;

	if (!a)
		return (-1);
	temp_stack = a;
	pos = 0;
	while ((*temp_stack)->top)
	{
		if ((*temp_stack)->top->data == min)
		{
			return (pos);
		}
		pos++;
		(*temp_stack)->top = (*temp_stack)->top->next;
	}
	return (-1);
}
