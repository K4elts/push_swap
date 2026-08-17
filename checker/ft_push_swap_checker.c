
#include "push_swap.h"
	
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

static int ft_do_push_swap_checker(t_push_swap_ops_data *operations_data)
{
	int is_stack_ordered;

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
	int		*flags;
	int		*numbers;
	int		numbers_count;

	// Si no se da argumento, checker termina y no muestra nada.
	if (argc < 2)
		ft_exit_program("", 1);
	numbers_count = ft_count_numbers(argc, argv);
	/*if (numbers_count < 1)
		ft_exit_program();*///PUEDE SER INECESARIA ESTA COMPROBACION EN EL CHECKER
	flags = ft_calloc(5, sizeof(int));
	numbers = malloc(sizeof(int) * numbers_count);
	if (!flags || !numbers)
		ft_exit_program("", 1);
	if (!ft_parse_args(argc, argv, flags, numbers))
	{
		free(flags);
		free(numbers);
		ft_exit_program("Error\n", 1);//-> que haya elementos duplicados
	}
	//ft_push_swap(flags, numbers, numbers_count);
	free(numbers);
	free(flags);
}