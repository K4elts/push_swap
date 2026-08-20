
#include "push_swap.h"


/// @brief Function that performs the recived operation on the stacks.
///operations_data->show_op = HIDE_OP
/// @param operation The operation to be performed on the stacks.
/// @param operations_data Struct that contains the stacks
/// and the operations count.
/// @return 1 if the operation was successful, 0 otherwise.
/// @see ft_strncmp & ft_putendl_fd
/// @authors jgilaber & aliao-tr
static int	ft_do_op(char *operation, t_push_swap_ops_data *ops_data)
{
	if (ft_strncmp(operation, "pa\n", 3) == 0)
		pa(ops_data);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		pb(ops_data);
	else if (ft_strncmp(operation, "sa\n", 3) == 0)
		sa(ops_data->a, ops_data->operations_count, ops_data->show_op);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		sb(ops_data->b, ops_data->operations_count, ops_data->show_op);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		ss(ops_data);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		ra(ops_data->a, ops_data->operations_count, ops_data->show_op);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rb(ops_data->b, ops_data->operations_count, ops_data->show_op);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rr(ops_data);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		rra(ops_data->a, ops_data->operations_count, ops_data->show_op);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		rrb(ops_data->b, ops_data->operations_count, ops_data->show_op);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		rrr(ops_data);
	else
		return (ft_putendl_fd("Error", STDERR_FILENO), 0);
	return (1);
}

/// @brief Function that reads operations from a file
/// and performs them on the stacks.
/// @param operations_data Struct that contains the stacks
/// and the operations count.
/// @return 1 if the operations were successful, 0 otherwise.
/// @authors jgilaber & aliao-tr
int	ft_read_operations(t_push_swap_ops_data *operations_data, int fd)
{
	char	*line;

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
/*
Durante la ejecución de checker se esperará y leerá una lista de instrucciones,
separadas utilizando ‘\n’. Cuando todas las instrucciones se hayan leído, checker
las ejecutará utilizando el stack recibido como argumento.

Si tras ejecutar todas las instrucciones, el stack a está ordenado y el stack b vacío,
entonces el programa checker mostrará “OK” seguido de un ‘\n’ en la ‘stdout’.
En cualquier otro caso, deberá mostrar “KO” seguido de un ‘\n’ en la ‘stdout’.

En caso de error, se deberá mostrar Error seguido de un ’\n’ en la ‘stderr’.
Los errores incluyen:
	-> algunos o todos los argumentos no sean enteros
	-> algunos o todos los argumentos sean más grandes que un número entero
	-> que haya elementos duplicados
	-> una instrucción no exista y/o no tenga el formato correcto.

EL ULTIMO PARRAFO DEBERIA SER EXACTAMENTE IGUAL QUE LA PARTE SIN BONUS. REVISAR Y COMPROBAR DIFERENCIAS.
*/
/// @brief 
/// @param operations_data 
static void ft_free_push_swap_checker(t_push_swap_ops_data *operations_data)
{
	ft_stack_clear(operations_data->a);
	ft_stack_clear(operations_data->b);
	free(operations_data->operations_count);
	free(operations_data);
}

static int	ft_do_push_swap_checker(t_push_swap_ops_data *operations_data)
{
	int	is_stack_ordered;

	// realizamos la lectura de las operaciones que previamente han sido escritas con gnl en FD_CHECKER_OUT
	if (!ft_read_operations(operations_data, FD_CHECKER_IN))
	{
		ft_free_push_swap_checker(operations_data);
		return (0);//Liberar numbers. En el checker no hay flags.
	}
	is_stack_ordered = ft_check_stack_order(*operations_data->a);
	if (is_stack_ordered && (*operations_data->b)->size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_free_push_swap_checker(operations_data);
	return (1);
}

/*
CREAMOS UN ARRAY DE OPERACIONES PARA GUARDARLAS EN FD_CHECKER_OUT CON GNL
*/
void ft_push_swap_checker(int argc, char **argv)
{
	
}
