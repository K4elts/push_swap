/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:49:24 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/17 21:53:25 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "strategy.h"

/// @brief Function that dispatch the stratergy tu use.
/// @param a stack_a
/// @param b stack_b
/// @return operations_count Int-Array that contains
/// the count of all type of operations.
/// operations_count = malloc(); --> habra que subirlo de nivel
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
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_simple_strategy(t_stack **a, t_stack **b, int *ops_count)
{
	int		min;
	int		pos;

	if (!(*a)->top)
		return ;
	while ((*a)->top != NULL)
	{
		min = ft_get_min_stack_node_index(a);
		pos = find_pos(a, min);
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
*/
/// @brief Medium Strategy Sorting Method with O(n√n) complexity.
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_medium_strategy(t_stack **a, t_stack **b, int *ops_count)
{
	if (!(*a)->top)
		return ;
	while ((*a)->top != NULL)
	{
		
	}
}

/* Implementa al menos un algoritmo perteneciente
	a la clase de complejidad O(n log n).
    • Adaptación del orden radix (LSD o MSD)
    • Adaptación del orden por fusión utilizando dos stacks
    • Adaptación del orden rápido con partición por stacks
    • Adaptación del orden por montículos
    • Algoritmos de árbol binario indexado
*/
/// @brief Complex Strategy Sorting Method with O(n log n) complexity.
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_complex_strategy(t_stack **a, t_stack **b, int *ops_count)
{
	if (!(*a)->top)
		return ;
	while ((*a)->top != NULL)
	{
		
	}
}

/// @brief Adaptative Strategy Sorting Method with O(n * k) complexity.
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_adaptative_strategy(t_stack **a, t_stack **b, int *ops_count)
{
	if ((*a)->disorder >= 0.5)
		ft_do_complex_strategy(a, b, ops_count);
	if ((*a)->disorder >= 0.2 && (*a)->disorder < 0.5)
		ft_do_medium_strategy(a, b, ops_count);
	else
		ft_do_simple_strategy(a, b, ops_count);
}
