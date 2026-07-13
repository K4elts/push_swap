/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:19:14 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/11 22:19:14 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funcion que determina la estrategia a utilizar en el proyecto.
void ft_push_swap_strategy_dispatcher(t_push_swap_strategy strategy) {}
/* Implementa al menos un algoritmo base perteneciente a la clase de complejidad O(n2).
    • Adaptación del orden por inserción
    • Adaptación del orden por selección
    • Adaptación del orden burbuja
    • Métodos simples de extracción del mínimo/máximo
*/

/// @brief Simple sorting method
/// @param a stack_a
/// @param b stack_b
void	ft_do_simple_strategy(t_stack **a, t_stack **b)
{
	int		min;
	int		pos;

	if (!(*a)->top)
		return ;
	while ((*a)->top != NULL)
	{
		min = find_min(a);
		pos = find_pos(a, min);
		if (pos <= ((*a)->size / 2))
		{
			while ((*a)->top->data != min)
				ra(a);
		}
		else
		{
			while ((*a)->top->data != min)
				rra(a);
		}
		pb(a, b);
	}
	while ((*b)->top)
		pa(a, b);
}

/* Implementa al menos un algoritmo perteneciente a la clase de complejidad O(n√n).
    • Orden basado en chunks (dividiendo en √n chunks)
    • Métodos de partición basados en bloques
    • Adaptaciones del orden por buckets con √n buckets
    • Estrategias de orden basadas en rangos
*/
void ft_do_medium_strategy(t_stack **a, t_stack **b) {}
/* Implementa al menos un algoritmo perteneciente a la clase de complejidad O(n log n).
    • Adaptación del orden radix (LSD o MSD)
    • Adaptación del orden por fusión utilizando dos stacks
    • Adaptación del orden rápido con partición por stacks
    • Adaptación del orden por montículos
    • Algoritmos de árbol binario indexado
*/
void ft_do_complex_strategy(t_stack **a, t_stack **b) {}
/* objetivos de complejidad para cada régimen (según el modelo de operaciones de Push_swap):
    Índice de desorden bajo: Si desorden < 0,2, el método elegido debe ejecutarse en O(n).
    Índice de desorden medio: Si 0,2 ≤ desorden < 0,5, el método elegido debe ejecutarse en O(n√n) -> medium.
    Índice de desorden alto: Si desorden ≥ 0,5, el método elegido debe ejecutarse en O(n log n) -> complex.
*/
void ft_do_adaptative_strategy(t_stack **a, t_stack **b) {}