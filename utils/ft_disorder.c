/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:09:00 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/31 16:24:35 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that compute the disorder of the recived stack.
/// @authors jgilaber & aliao-tr
/// @param s stack_s
/// @return double The disorder computed
double	ft_do_disorder(t_stack *s)
{
	t_stack_node *tmp_stack_node;
	int		total_pairs;
	double	mistakes;

	mistakes = 0;
	total_pairs = 0;
	while (s->top->next)
	{
		tmp_stack_node = s->top->next;
		while (tmp_stack_node)
		{
			if (s->top->data > tmp_stack_node->data)
				mistakes += 1;
			total_pairs += 1;
			tmp_stack_node = tmp_stack_node->next;
		}
		s->top = s->top->next;
	}
	return (mistakes / total_pairs);
}
