/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:09:00 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/31 16:24:35 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that displays an error message and exits the program.
/// @param exit_message The error message to be displayed.
/// @param exit_code The exit code to be returned.
/// @return Nothing
/// @see ft_putendl_fd
/// @authors jgilaber & aliao-tr
void	ft_exit_program(char *exit_message, int exit_code)
{
	ft_putendl_fd(exit_message, STDERR_FILENO);
	exit(exit_code);
}

/// @brief Function that compute the disorder of the recived stack.
/// @param stack The stack to compute the disorder from.
/// @return double The disorder computed
/// @authors jgilaber & aliao-tr
double	ft_get_disorder(t_stack **stack)
{
	double	mistakes;
	int		total_pairs;
	t_stack_node *tmp_stack_node;
	t_stack_node *tmp2_stack_node;

	mistakes = 0;
	total_pairs = 0;
	tmp_stack_node = (*stack)->top;
	while (tmp_stack_node->next)
	{
		tmp2_stack_node = tmp_stack_node->next;
		while (tmp2_stack_node)
		{
			if (tmp_stack_node->data > tmp2_stack_node->data)
				mistakes += 1;
			total_pairs += 1;
			tmp2_stack_node = tmp2_stack_node->next;
		}
		tmp_stack_node = tmp_stack_node->next;
	}
	return (mistakes / total_pairs);
}

/// @brief Function that performs the recived operation on the stacks.
/// @param operation The operation to be performed on the stacks.
/// @param operations_data Struct that contains the stacks and the operations count.
/// @return 1 if the operation was successful, 0 otherwise.
/// @see ft_strncmp & ft_putendl_fd
/// @authors jgilaber & aliao-tr
static int	ft_do_op(char *operation, t_push_swap_ops_data *operations_data)//operations_data->show_op = HIDE_OP
{
	if (ft_strncmp(operation, "pa\n", 3) == 0)
		pa(operations_data);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		pb(operations_data);
	else if (ft_strncmp(operation, "sa\n", 3) == 0)
		sa(operations_data->a, operations_data->operations_count, operations_data->show_op);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		sb(operations_data->b, operations_data->operations_count, operations_data->show_op);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		ss(operations_data);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		ra(operations_data->a, operations_data->operations_count, operations_data->show_op);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rb(operations_data->b, operations_data->operations_count, operations_data->show_op);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rr(operations_data);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		rra(operations_data->a, operations_data->operations_count, operations_data->show_op);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		rrb(operations_data->b, operations_data->operations_count, operations_data->show_op);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		rrr(operations_data);
	else
		return (ft_putendl_fd("Error", STDERR_FILENO), 0);
	return (1);
}

/// @brief Function that reads operations from a file and performs them on the stacks.
/// @param operations_data Struct that contains the stacks and the operations count.
/// @return 1 if the operations were successful, 0 otherwise.
/// @authors jgilaber & aliao-tr
int ft_read_operations(t_push_swap_ops_data *operations_data, int fd)
{
	char *line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!ft_do_op(line, operations_data))
			return (0);
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

/// @brief Checks if the recived stack is sorted.
/// An empty stack is considered sorted.
/// @param stack Pointer to the stack to check.
/// @return 1 if the stack is sorted, 0 otherwise.
/// @authors jgilaber & aliao-tr
int ft_check_stack_order(t_stack *stack)
{
    t_stack_node *current;

    if (!stack || !stack->top)
        return (1);
    current = stack->top;
    while (current->next)
    {
        if (current->data > current->next->data)
            return (0);
        current = current->next;
    }
    return (1);
}