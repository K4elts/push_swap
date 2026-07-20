
#include "stacklib.h"

/// @brief Function that update all stack_node index
/// @param s stack_s
void	ft_stack_update_index(t_stack **s)
{
	size_t	index;

	if (!s)
		return ;
	index = 0;
	while ((*s)->top)
	{
		(*s)->top->index = index++;
		(*s)->top = (*s)->top->next;
	}
}

/// @brief Finds the lowest number on the stack
/// @param a stack_a
/// @return min - The lowest number on the stack
/// SUJETO A REVISION POR ANDRES.
int	ft_get_min_stack_node_index(t_stack **a)
{
	int		min_stack_node_index;
	t_stack	**temp_stack;

	temp_stack = a;
	if (a == NULL)
		return (-1);
	min_stack_node_index = (*temp_stack)->top->index;
	while ((*temp_stack)->top)
	{
		if ((*temp_stack)->top->index < min_stack_node_index)
			min_stack_node_index = (*temp_stack)->top->index;
		(*temp_stack)->top = (*temp_stack)->top->next;
	}
	return (min_stack_node_index);
}
