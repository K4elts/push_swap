/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:11:23 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/11 23:06:48 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_do_swap_op(t_stack **s)
{
	t_stack_node	*first_stack_node_tmp;

	if ((*s)->size < 2)
		return ;
	// Nos guardamos el puntero al primer valor del stack.
	first_stack_node_tmp = (*s)->top;
	// Avanzamos el puntero para que el actual top del stack sea el segundo elemento.
	(*s)->top = (*s)->top->next;
	// Indicamos que el elemento actual(top) no tiene un nodo previo.
	(*s)->top->prev = NULL;
	// Indicamos que el nuevo segundo nodo del stack tiene como previo el actual(el primero nodo/top).
	first_stack_node_tmp->prev = (*s)->top;
	// Indicamos que el nuevo segundo nodo del stack tiene como siguiente el siguiente del actual(osea el tercer nodo).
	first_stack_node_tmp->next = (*s)->top->next;
	// Actualizamos el puntero del tercer nodo del stack para que tenga como nodo previo el nuevo segundo nodo que antes era el primero.
	(*s)->top->next->prev = first_stack_node_tmp;
	// Actualizamos el puntero actual(top) para que tenga como siguiente el nuevo segundo nodo que antes era el primero.
	(*s)->top->next = first_stack_node_tmp;
	// SI AL FINAL CREAMOS LOS NODOS CON MALLOC, HABRA QUE HACER -> free(first_stack_node_tmp);
}

void	sa(t_stack **a)
{
	ft_do_swap_op(a);
}

void	sb(t_stack **b)
{
	ft_do_swap_op(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);//¿sa(&a);?
	sb(b);//¿sb(&b);?
}
