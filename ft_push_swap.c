/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:18:13 by jgilaber          #+#    #+#             */
/*   Updated: 2026/08/17 17:38:51 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

///USO: FUNCION TEMPORAL PARA MOSTRAR EL STACK, ELIMINAR TRAS SU USO EN LAS PRUEBAS.
void ft_stack_print(t_stack *stack)
{
	t_stack_node *current;

	if (!stack || !stack->top)
	{
		printf("Stack is empty.\n");
		return;
	}

	current = stack->top;
	printf("Stack (size: %zu): ", stack->size);
	while (current)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
}


/// @brief Frees the memory allocated for the push_swap algorithm.
/// @param stack_a Pointer to the first stack.
/// @param stack_b Pointer to the second stack.
/// @param operations_count Pointer to an array that will hold the count of operations performed.
/// @return Nothing
/// @see ft_stack_clear
/// @authors jgilaber & aliao-tr
static void ft_free_push_swap(
	t_stack **stack_a, t_stack **stack_b, int *ops_count)
{
	ft_stack_clear(stack_a);
	ft_stack_clear(stack_b);
	free(ops_count);
}

/// @brief Executes the push_swap algorithm on the provided stacks and counts operations.
/// @param stack_a Pointer to the first stack.
/// @param stack_b Pointer to the second stack.
/// @param operations_count Pointer to an array that will hold the count of operations performed.
/// @return Returns 1 on success, 0 on failure (e.g., memory allocation failure).
/// @see ft_do_disorder & ft_exec_strat_dispatch
/// @authors jgilaber & aliao-tr
static int ft_do_push_swap(t_stack **stack_a, t_stack **stack_b, int *operations_count)
{
	t_push_swap_ops_data	*operations_data;

	operations_data = malloc(sizeof(t_push_swap_ops_data));
	if (!operations_data)
		return (0);
	operations_data->a = stack_a;
	operations_data->b = stack_b;
	operations_data->show_op = SHOW_PUSH_SWAP_OPERATION;
	operations_data->operations_count = operations_count;
	(*operations_data->a)->disorder = ft_get_disorder(stack_a);
	ft_stack_print(*stack_a);
	ft_exec_strat_dispatch(operations_data);
	ft_stack_print(*stack_a);
	free(operations_data);//ESTO PUEDE ESTAR MAL, REVISAR SI ESTO SE PUEDE HACER LIBERANDO DESPUES SU CONTENIDO EN ft_push_swap(REVISAR ANTES CON TORTURETTE Y VER SE HAY MEM-LEAK AQUI/CON ESA LINEA)
	return (1);
}

/// @brief Creates and initializes the stacks, fills them with numbers,
/// executes the push_swap algorithm(ft_do_push_swap), and handles cleanup.
/// @param flags Flags de configuración del programa.
/// @param numbers Array de números que contiene los valores a ordenar.
/// @param number_size Tamaño del array de números a ordenar.
/// @return Returns 1 on success, 0 on failure (e.g., memory allocation failure).
/// @see ft_fill_stack, ft_do_push_swap, ft_show_benchmark, ft_stack_clear
/// @authors jgilaber & aliao-tr
static void ft_push_swap(int *flags, int *numbers, int numbers_size)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*ops_count;
	int			stack_filled_failure;
	int 		memory_allocation_failure;

	stack_b = ft_new_stack(-1);
	stack_a = ft_new_stack(ft_get_strategy_flag(flags));
	ops_count = ft_calloc(OP_TOTAL + 1, sizeof(int));
	memory_allocation_failure = !stack_a || !stack_b || !ops_count;
	if (memory_allocation_failure)
	{
		ft_free_push_swap(&stack_a, &stack_b, ops_count);
		return ;
	}
	stack_filled_failure = !ft_fill_stack(&stack_a, numbers, numbers_size);
	if (stack_filled_failure || !ft_do_push_swap(&stack_a, &stack_b, ops_count))
	{
		ft_free_push_swap(&stack_a, &stack_b, ops_count);
		return ;
	}
	if (flags[4] == 1)
		ft_show_benchmark(stack_a, ops_count);
	ft_free_push_swap(&stack_a, &stack_b, ops_count);
}

/// @brief Main function of the program.
/// @param argc Number of arguments.
/// @param argv Array of arguments.
/// @return Exit status of the program.
/// @see ft_exit_program, ft_count_numbers, ft_parse_args, ft_push_swap
/// @authors jgilaber & aliao-tr
int	main(int argc, char **argv)
{
	int		*flags;
	int		*numbers;
	int		numbers_count;

	if (argc < 2)
		return (1);
	numbers_count = ft_count_numbers(argc, argv);
	if (numbers_count < 1)
		return (1);
	flags = ft_calloc(5, sizeof(int));
	numbers = malloc(sizeof(int) * numbers_count);
	if (!flags || !numbers)
		return (1);//posible ft_exit_program("¿Error?", 1);
	if (!ft_parse_args(argc, argv, flags, numbers))
	{
		free(flags);
		free(numbers);
		ft_exit_program("Error", 1);//-> que haya elementos duplicados ¿TAMBIEN CUENTA COMO "Error" SI HAY FLAGS DUPLICADAS?
	}
	ft_push_swap(flags, numbers, numbers_count);
	free(numbers);
	free(flags);
	return (0);
}
