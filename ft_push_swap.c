/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:18:13 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/31 17:24:17 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/// @brief 
/// @param argc 
/// @param argv 
/// @return 
int	main(int argc, char **argv)
{
	t_push_swap_ops_data	*operations_data;
	int						*numbers;
	int						*flags;
	t_stack					*new_stack_a;
	t_stack					*new_stack_b;
	int						*operations_count;

	flags = malloc(sizeof(int) * 5);
	if (!flags)
		return (1);
	numbers = do_parser(argc, argv, flags);
	if (!numbers)
		return (1);
	operations_data = malloc(sizeof(t_push_swap_ops_data));
	if (!operations_data)
		return (1);
	new_stack_a = ft_new_stack(
			numbers, get_flag(flags), count_numbers(argc, argv));
	if (!new_stack_a)
		return (1);
	new_stack_b = malloc(sizeof(t_stack));
	if (!new_stack_b)
		return (1);
	operations_count = malloc(sizeof(int) * (OP_TOTAL + 1));
	if (!operations_count)
		return (1);
	operations_data->a = &new_stack_a;
	operations_data->operations_count = operations_count;
	new_stack_b->top = NULL;
	new_stack_b->size = 0;
	operations_data->b = &new_stack_b;
	//(*operations_data->a)->disorder = ft_do_disorder((*operations_data->a));
	(*operations_data->a)->disorder = 0;
	printf("size: %zu\n", (*operations_data->a)->size);
	if ((*operations_data->a)->size <= 5)
		ft_sort_small(&(*operations_data));
	else
		ft_exec_strat_dispatch(operations_data);
	printf("disorder: %f\n\n", (*operations_data->a)->disorder);
	while ((*operations_data->a)->top)
	{
		printf("%d ", (*operations_data->a)->top->data);
		(*operations_data->a)->top = (*operations_data->a)->top->next;
	}
	if (flags[4] == 1)
		ft_show_benchmark(
			operations_data->a, operations_data->operations_count);
	printf("\n%d %d %d %d %d\n",
		flags[0], flags[1], flags[2], flags[3], flags[4]);
	free(flags);
	return (0);
}
