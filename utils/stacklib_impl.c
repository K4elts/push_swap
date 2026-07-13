/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklib_impl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:00:28 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/11 22:47:48 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacklib.h"

t_stack_node	*ft_stack_last(t_stack *stack)
{
	if (!stack || !stack->top)// == NULL
		return (NULL);
	while (stack->top->next)
		stack->top = stack->top->next;
	return (stack->top);
}
