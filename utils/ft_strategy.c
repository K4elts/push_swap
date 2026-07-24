/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:49:24 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/23 22:31:53 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "strategy.h"
#include "stacklib.h"

/// @brief Function that dispatch the stratergy tu use.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
void	ft_exec_strat_dispatch(t_stack **a, t_stack **b, int *ops_count)
{
	t_strategy	strategy_used;

	if (!(*a)->top || !(*b)->top)
		return ;
	strategy_used = (*a)->strategy_used;
	if (strategy_used == STRAT_SIMPLE)
		ft_do_simple_strategy(a, b, ops_count);
	else if (strategy_used == STRAT_MEDIUM)
		ft_do_medium_strategy(a, b, ops_count);
	else if (strategy_used == STRAT_COMPLEX)
		ft_do_complex_strategy(a, b, ops_count);
	else
		ft_do_adaptative_strategy(a, b, ops_count);
}

/// @brief Simple sorting method O(n2)
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
/// SUJETO A REVISION POR ANDRES.
void	ft_do_simple_strategy(t_stack **a, t_stack **b, int *ops_count)
{
	int		min;
	int		pos;

	if (!(*a)->top)
		return ;
	while ((*a)->top != NULL)
	{
		min = ft_get_min_stack_node_index(a);
		pos = ft_get_min_stack_node_position(a, min);
		if (pos <= ((*a)->size / 2))
			while ((*a)->top->index != min)
				ra(a, ops_count);
		else
			while ((*a)->top->index != min)
				rra(a, ops_count);
		pb(a, b, ops_count);
	}
	while ((*b)->top)
		pa(a, b, ops_count);
}

/* Algoritmo perteneciente a la clase de complejidad O(n√n).
    • Orden basado en chunks (dividiendo en √n chunks)
    • Métodos de partición basados en bloques
    • Adaptaciones del orden por buckets con √n buckets
    • Estrategias de orden basadas en rangos

La idea sería:

Normalizar los números (darles un índice de 0 a n-1).
Dividir esos índices en aproximadamente √n chunks.
Mientras procesas un chunk, aceptar cualquier elemento que pertenezca a ese rango, sin buscar uno concreto.
Al enviarlo a B, colocarlo de forma que facilite recuperarlo después (por ejemplo, decidiendo cuándo conviene hacer una rotación en B).

Esa última parte es donde se gana mucha eficiencia.


Aquí está el detalle importante: no suele ser el tamaño de los chunks, sino cómo gestionas la pila B.

Dos personas pueden usar exactamente los mismos chunks.

Una hace:
	A → B
	y luego busca siempre el máximo en B.

La otra:
	mientras envía elementos a B, intenta que los grandes queden más arriba y los pequeños más abajo.

La segunda hará muchas menos rotaciones al reconstruir A.

Ahí es donde se suelen ahorrar decenas o incluso cientos de movimientos.


Normalizar los números a índices de 0 a n-1.
Elegir un número de chunks (una aproximación a √n es un buen punto de partida).
Procesar un chunk cada vez, buscando cualquier elemento que pertenezca a ese rango.
Optimizar el envío a B, para que quede parcialmente ordenada.
Reconstruir A extrayendo de B los elementos en el orden adecuado con el menor número posible de rotaciones.
*/
/// @brief Medium Strategy Sorting Method with O(n√n) complexity.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_medium_strategy(t_stack **a, t_stack **b, int *ops_count)
{
	int chunk_it;
	int nbr_chunks;
	t_stack_node	*a_stack_node;
	t_stack_node	*b_stack_node;

	if (!a || !(*a)->top)
		return ;
	a_stack_node = (*a)->top;
	b_stack_node = (*b)->top;
	chunk_it = 0;
	//√100 = 10 -> tenemos 10 chunks de 10 elementos cada uno.
	nbr_chunks = ft_get_sqrt((*a)->size);
	while (chunk_it < nbr_chunks)
	{
		while (a_stack_node != NULL)
		{
			if (a_stack_node->index >= (chunk_it * 10) && a_stack_node->index <= (chunk_it * 10) + 9)
				pb(a, b, ops_count);
			while (b_stack_node->index)
			{
				/* code */
			}
			
		}
		chunk_it++;
	}
	while ((*b)->top)
		pa(a, b, ops_count);
}
int ft_check_chunk_range()
{}

/* Implementa al menos un algoritmo perteneciente
	a la clase de complejidad O(n log n).
    • Adaptación del orden radix (LSD o MSD)
    • Adaptación del orden por fusión utilizando dos stacks
    • Adaptación del orden rápido con partición por stacks
    • Adaptación del orden por montículos
    • Algoritmos de árbol binario indexado
*/
/// @brief Complex Strategy Sorting Method with O(n log n) complexity.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_complex_strategy(t_stack **a, t_stack **b, int *ops_count)
{
	if (!a || !(*a)->top)
		return ;
}

/// @brief Adaptative Strategy Sorting Method with O(n * k) complexity.
/// @authors jgilaber & aliao-tr
/// Is the default strategy if no other strategy is selected.
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_adaptative_strategy(t_stack **a, t_stack **b, int *ops_count)
{
	if ((*a)->disorder >= 0.5)
		ft_do_complex_strategy(a, b, ops_count);
	if ((*a)->disorder < 0.2)
		ft_do_simple_strategy(a, b, ops_count);
	else
		ft_do_medium_strategy(a, b, ops_count);
}
