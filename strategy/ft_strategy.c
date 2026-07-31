/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:49:24 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/31 16:19:32 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that dispatch the stratergy tu use.
/// @authors jgilaber & aliao-tr
/// @pre operations_data != NULL
/// @param operations_data Estructura con los stacks y operaciones.
/// @return Nothing
void	ft_exec_strat_dispatch(t_push_swap_ops_data *operations_data)
{
	t_strategy_type	strategy;

	if (!(*operations_data->a)->top)
	{
		// habra que hacer exit siempre que haya este tipo de errores en todo el proyecto.
		printf("Error from ft_exec_strat_dispatch");
		return ;
	}
	strategy = (*operations_data->a)->strategy_used;
	if (strategy == STRAT_SIMPLE)
		ft_do_simple_strategy(operations_data);
	else if (strategy == STRAT_MEDIUM)
		ft_do_medium_strategy(operations_data);
	else if (strategy == STRAT_COMPLEX)
		ft_do_complex_strategy(operations_data);
	else
		ft_do_adaptative_strategy(operations_data);
}

/// @brief Simple sorting method O(n2)
/// @authors jgilaber & aliao-tr
/// @pre operations_data != NULL
/// @param operations_data Estructura con los stacks y operaciones.
/// @return Nothing
void	ft_do_simple_strategy(t_push_swap_ops_data *operations_data)
{
	size_t	min;
	size_t	pos;

	while ((**operations_data->a).top)
	{
		min = ft_get_min_stack_node_index(operations_data->a);
		pos = ft_get_min_stack_node_pos(operations_data->a, min);
		//printf("\nmin=%zu pos=%zu\n", min, pos);
		if (pos <= ((*operations_data->a)->size / 2))
			while ((*operations_data->a)->top && (*operations_data->a)->top->index != min)
			{
				//printf("\nantes ra top=%p\n", (void *)(*operations_data->a)->top);
				ra(operations_data->a, operations_data->operations_count, 1);
				//printf("\ndespues ra top=%p\n", (void *)(*operations_data->a)->top);
			}
		else
			while ((*operations_data->a)->top && (*operations_data->a)->top->index != min)
			{
				//printf("\nantes rra top=%p\n", (void *)(*operations_data->a)->top);
				rra(operations_data->a, operations_data->operations_count, 1);
				//printf("\ndespues rra top=%p\n", (void *)(*operations_data->a)->top);
			}
		//printf("\nantes pb top=%p\n", (void *)(*operations_data->a)->top);
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

normalizar/indexar
establecer un tamaño de chunk(chunk_size).
para cada chunk:
    mientras exista un elemento del chunk:
        si es el primero del stack
            pb
            si pertenece a la mitad baja del chunk
                rb
        si no es el primero del stack
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
/// @param operations_data Estructura con los stacks y operaciones.
/// @return Nothing
/// UNA VEZ SE HAYA COMPROBADO QUE FUNCIONA, REALIZAR CAMBIOS EN MAKEFILE YA QUE JGILA HA TRABAJADO SOBRE WIN EN VEZ DE LINUX(mingw32-make)
void	ft_do_medium_strategy(t_push_swap_ops_data *operations_data)
{
	// medium empezando en 39 hace: mal ordenado
	// medium empezando en 189 hace: segfault
	int	chunk_size;

	if ((*operations_data->a)->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	ft_do_medium_strategy_operations(operations_data, chunk_size);
	ft_do_medium_strategy_reconstruction(operations_data);
}

/* Radix Sort (LSD o MSD)
Complejidad
    Tiempo: O(n · k), donde k es el número de bits o dígitos.
Idea
    No compara números entre sí.
    Ordena mirando un bit (o un dígito) cada vez.
Ejemplo -> 7 2 5 1
En binario
    7 = 111
    2 = 010
    5 = 101
    1 = 001
Primero mira el bit menos significativo.
    111 -> 1
    010 -> 0
    101 -> 1
    001 -> 1
Todos los que tienen 0 van a un lado.
Después vuelve y mira el siguiente bit.
Luego el siguiente.
Al terminar todos los bits, está ordenado.


¿Por qué funciona tan bien en push_swap?
Porque separar según un bit es exactamente lo que hacen dos stacks.
    bit = 0 -> pb
    bit = 1 -> ra
Después recuperas con pa.
No necesitas comparar elementos.

La frase que debes recordar para 42:
    En push_swap con radix LSD no ordenas B; solo particionas por bits de forma estable.

Y la estabilidad aparece gracias a -> pb + pa = doble inversión = orden preservado
Cuando entiendes eso, el algoritmo deja de parecer magia y pasa a ser simplemente una serie de particiones estables por bits.
*/
/// @brief Complex Strategy Sorting Method with O(n log n) complexity.
/// @authors jgilaber & aliao-tr
/// @pre operations_data != NULL
/// @param operations_data Estructura con los stacks y operaciones.
/// @return Nothing
/// @deprecated ELIMINAR ESTA BASURA DE FUNCION CUANDO SE HAYA COMPRENDIDO EL FUNCIONAMIENTO DE LA NUEVA MEDIANTE CHATGPT.
/*void	ft_do_complex_strategy_old(t_push_swap_ops_data *operations_data)
{
	int		lsd_bit;
	size_t	lsd_bit_index;

	printf("executing ft_do_complex_strategy\n");
	lsd_bit_index = 0;
	while (lsd_bit_index < (*operations_data->a)->size)
	{
		while ((*operations_data->a)->top)
		{
			lsd_bit = ft_get_lsd_bit(
					(*operations_data->a)->top->data, lsd_bit_index);
			printf("lsd_bit -> %d\n", lsd_bit);
			if (lsd_bit == 1)
				ra(operations_data->a, operations_data->operations_count, 1);
			else if (lsd_bit == 0)
				pb(operations_data);
			else
				return ;
		}
		while ((*operations_data->b)->top)
			pa(operations_data);
		lsd_bit_index++;
	}
}*/
void	ft_do_complex_strategy(t_push_swap_ops_data *operations_data)
{
	size_t	bit;
	size_t	max_bits;
	size_t	stack_size;
	size_t	processed_nodes_count;

	stack_size = (*operations_data->a)->size;
	max_bits = 0;
	while (((stack_size - 1) >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		processed_nodes_count = 0;
		while (processed_nodes_count < stack_size)
		{
			if ((((*operations_data->a)->top->index >> bit) & 1) == 0)
				pb(operations_data);
			else
				ra(operations_data->a, operations_data->operations_count, 1);
			processed_nodes_count++;
		}
		while ((*operations_data->b)->top)
			pa(operations_data);
		bit++;
	}
}

/// @brief Adaptative Strategy Sorting Method with O(n * k) complexity.
/// @note Is the default strategy if no other strategy is selected.
/// @authors jgilaber & aliao-tr
/// @see ft_do_simple_strategy, ft_do_medium_strategy, ft_do_complex_strategy
/// @pre operations_data != NULL
/// @param operations_data Estructura con los stacks y operaciones.
/// @return Nothing
void	ft_do_adaptative_strategy(t_push_swap_ops_data *operations_data)
{
	if ((*operations_data->a)->disorder >= 0.5)
		ft_do_complex_strategy(operations_data);
	else if ((*operations_data->a)->disorder < 0.2)
		ft_do_simple_strategy(operations_data);
	else
		ft_do_medium_strategy(operations_data);
}
