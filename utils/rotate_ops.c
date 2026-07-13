/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:11:47 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/13 18:35:02 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_do_rotate_op(t_stack **s)
{
	t_stack_node	*first_stack_node_tmp;
	t_stack_node	*last_stack_node_tmp;

	if ((*s)->size < 2)
		return ;
	// Nos guardamos el puntero al primer valor del stack.
	first_stack_node_tmp = (*s)->top;
	// Avanzamos el puntero para que el actual top del stack sea el segundo elemento.
	(*s)->top = (*s)->top->next;
	// Indicamos que el elemento actual(top) no tiene un nodo previo ya que antes tenia como previo el primero(first_stack_node_tmp).
	(*s)->top->prev = NULL;
	// Obtenemos el ultimo nodo del stack.
	last_stack_node_tmp = ft_stack_last(*s);
	// Indicamos que el nuevo ultimo nodo del stack(el que antes era el primero) tendra como nodo previo el ultimo del stack.
	first_stack_node_tmp->prev = last_stack_node_tmp;
	// Indicamos que el nuevo ultimo nodo del stack(el que antes era el primero) no tendra ningun nodo siguiente.
	first_stack_node_tmp->next = NULL;
	// Actualizamos el puntero indicando que el ultimo elemento del stack tendra como siguiente el anterior primer elemento del stack.
	last_stack_node_tmp->next = first_stack_node_tmp;
	// SI AL FINAL CREAMOS LOS NODOS CON MALLOC, HABRA QUE HACER -> free(first_stack_node_tmp);
}

// ra() -> Desplaza hacia arriba todos los elementos del stack a una posición, convirtiendo el primer elemento en el último.
void	ra(t_stack **a)
{
	ft_do_rotate_op(a);
}

// rb() -> Desplaza hacia arriba todos los elementos del stack b una posición, convirtiendo el primer elemento en el último.
void	rb(t_stack **b)
{
	ft_do_rotate_op(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);//¿ra(&a);?
	rb(b);//¿rb(&b);?
}
