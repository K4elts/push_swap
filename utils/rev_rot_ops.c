/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:12:12 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/11 22:13:28 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_do_reverse_rotate_op(t_stack **s)
{
	t_stack_node	*first_stack_node_tmp;
	t_stack_node	*last_stack_node_tmp;

	if ((*s)->size < 2)
		return ;
	// Nos guardamos el puntero al primer valor del stack.
	first_stack_node_tmp = (*s)->top;
	// Nos guardamos el puntero al ultimo valor del stack.
	last_stack_node_tmp = ft_stack_last(*s);
	// Indicamos que el nodo anterior al ultimo del stack ya no tendra ningun siguiente nodo asociado.
	last_stack_node_tmp->prev->next = NULL;
	// Indicamos que el nuevo primer nodo no tendra ningun nodo previo asociado.
	last_stack_node_tmp->prev = NULL;
	// Indicamos que el nuevo primer nodo tendra como siguiente el nuevo segundo nodo.
	last_stack_node_tmp->next = first_stack_node_tmp;
	// Indicamos que el nuevo segundo nodo tendra como nodo previo al nuevo primer nodo(last_stack_node_tmp).
	first_stack_node_tmp->prev = last_stack_node_tmp;
	// Actualizamos el puntero actual(top) para que tenga como nuevo top el anterior ultimo nodo.
	(*s)->top = last_stack_node_tmp;
	// SI AL FINAL CREAMOS LOS NODOS CON MALLOC, HABRA QUE HACER -> free(first_stack_node_tmp);
}

void	rra(t_stack **a)
{
	ft_do_reverse_rotate_op(a);
}

void	rrb(t_stack **b)
{
	ft_do_reverse_rotate_op(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);//¿rra(&a);?
	rrb(b);//¿rrb(&b);?
}
