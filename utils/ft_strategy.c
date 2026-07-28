/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:49:24 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/27 19:27:01 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that dispatch the stratergy tu use.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
void	ft_exec_strat_dispatch(t_push_swap_ops_data *operations_data)
{
	t_strategy_type	strategy_used;

	if (!(*operations_data->a)->top || !(*operations_data->b)->top)
		return ;
	strategy_used = (*operations_data->a)->strategy_used;
	if (strategy_used == STRAT_SIMPLE)
		ft_do_simple_strategy(operations_data);
	else if (strategy_used == STRAT_MEDIUM)
		ft_do_medium_strategy(operations_data);
	else if (strategy_used == STRAT_COMPLEX)
		ft_do_complex_strategy(operations_data);
	else
		ft_do_adaptative_strategy(operations_data);
}

/// @brief Simple sorting method O(n2)
/// @authors jgilaber & aliao-tr
/// @param operations_data
/// @return Nothing
/// SUJETO A REVISION POR ANDRES.
void	ft_do_simple_strategy(t_push_swap_ops_data *operations_data)
{
	int		min;
	int		pos;

	while ((*operations_data->a)->top != NULL)
	{
		min = ft_get_min_stack_node_index(operations_data->a);
		pos = ft_get_min_stack_node_pos(operations_data->a, min);
		if (pos <= ((*operations_data->a)->size / 2))
			while ((*operations_data->a)->top->index != min)
				ra(operations_data->a, operations_data->operations_count, 1);
		else
			while ((*operations_data->a)->top->index != min)
				rra(operations_data->a, operations_data->operations_count, 1);
		pb(operations_data);
	}
	while ((*operations_data->b)->top)
		pa(operations_data);
}

/* Algoritmo perteneciente a la clase de complejidad O(n√n).
    • Orden basado en chunks (dividichunk_range_endo en √n chunks)
    • Métodos de partición basados en bloques
    • Adaptaciones del orden por buckets con √n buckets
    • Estrategias de orden basadas en rangos

normalizar
chunk_size = sqrt(size)
para cada chunk:
    mientras exista un elemento del chunk:
        si está arriba
            pb
            si pertenece a la mitad baja del chunk
                rb
        si no
            ra
fin
mientras B no esté vacía:
    localizar máximo
    rb o rrb (el camino más corto)
    pa
fin
*/
/// @brief Medium Strategy Sorting Method with O(n√n) complexity.
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_medium_strategy(t_push_swap_ops_data *operations_data)
{
	int	chunk_size;

	if ((*operations_data->a)->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	ft_do_medium_strategy_operations(operations_data, chunk_size);
	ft_do_medium_strategy_reconstruction(operations_data);
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
/// @authors jgilaber & aliao-tr
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_complex_strategy(t_push_swap_ops_data *operations_data)
{
	
}

/// @brief Adaptative Strategy Sorting Method with O(n * k) complexity.
/// @authors jgilaber & aliao-tr
/// Is the default strategy if no other strategy is selected.
/// @param a stack_a
/// @param b stack_b
/// @return Nothing
void	ft_do_adaptative_strategy(t_push_swap_ops_data *operations_data)
{
	if ((*operations_data->a)->disorder >= 0.5)
		ft_do_complex_strategy(operations_data);
	if ((*operations_data->a)->disorder < 0.2)
		ft_do_simple_strategy(operations_data);
	else
		ft_do_medium_strategy(operations_data);
}
