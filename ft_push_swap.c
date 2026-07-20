/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:18:13 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/17 21:57:42 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
/*
static int	ft_do_op(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(operation, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(operation, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(operation, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(operation, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(operation, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(a, b);
	else
		return (1);
}

void ft_read_instructions(t_stack **a, t_stack **b)
{
	char *line;

	line = get_next_line(0);
	while (line != NULL)
	{
		ft_do_op(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}*/

void	ft_push_swap(t_stack **a, t_stack **b, int **nbr_list)
{
	// El índice de desorden se calculará antes de hacer ningún movimiento.
	// Establecemmos el valor de disorder del stack_a al obtenido de ft_do_compute_disorder(t_stack **s)
	int	*operations_count;

	operations_count = malloc(sizeof(int) * OP_TOTAL);
	ft_exec_strat_dispatch(a, b, operations_count);
}

int	main(int argc, char **argv)
{
	int	argv_row;
	int	argv_col;
	int	**nbr_list;

	argv_row = 0;
	nbr_list = malloc((argc - 1) * sizeof(int *));
	if (!nbr_list)
		return (1);
	while ((argc - 1) > 0)
	{
		argv_col = 0;
		nbr_list[argv_row] = malloc((ft_strlen(argv[argv_row]) + 1)//argv[argv_row + 1]
				* sizeof(int));
		while (argv[argv_row])
		{
			while (argv[argv_row][argv_col])
			{
				nbr_list[argv_row][argv_col] = argv[argv_row][argv_col];
				argv_col++;
			}
			argv_row++;
		}
		argc--;
	}
	ft_push_swap(nbr_list);
	return (0);
}

//en main ahora: Recorre los argumentos y los guarda en un array para mostrarlos
//Hay que comprobar que solo haya numeros, no haya numeros duplicados, si introduce varios signos + o -
//Si cada numero es un argumentos se guardan tal cual, ejemplo: ./push_swap 5 2 9 -1
//en caso de que se pasen en un solo argumento, ejemplo: ./push_swap "1 6 -2 54" hacer split para separar los numeros y guardarlos.
//en cuanto al indice habrá que hacer algun tipo de indexacion para que cada nodo tenga guardado el indice que le corresponda:
//IDEA??: guardar en array -> con copia ordenada del array -> comparar los dos array para saber el indice que deberia tener el numero con la lista ordenada
/*
int	main(int argc, char **argv)
{
	int	*array;
	int	i;

	if (argc < 2)
		return (printf("Error"), -1);
	array = fill_array(argc, argv);
	i = 0;
	while (array[i])
	{
		printf("valor: %d\n", array[i]);
		i++;
	}
	return (0);
}
	
JGILABERT NOTES:
	int ft_check_argv(); Funcion que utiliza ft_isdigit() para comprobar si los argumentos son todos numeros. Devuelve 1 si todos los argumentos son numeros.

	//en cuanto al indice habrá que hacer algun tipo de indexacion para que cada nodo tenga guardado el indice que le corresponda:
	ESO SE SUPONE QUE ESTA HECHO YA CON index en la struct que define un t_stack. ESO SI, HABRIA QUE ACTUALIZARLO AUTMATICAMENTE PARA TODOS LOS ELEMENTOS DEL STACK CADA VEZ QUE SE REALIZA UNA OPERACION Y ES UNA FUMADERA XD, PERO HABRA QUE HACERLO.
*/
// Devuelve 1 si hay elementos duplicados, ya sean numeros o signos. (Sujeto a cambios/correcciones)
int	ft_check_duplicated_values(char *array)
{
	int	array_row_index;
	int	array_col_index;

	array_row_index = 0;
	while (array[array_row_index])
	{
		array_col_index = 0;
		while (array[array_col_index])
		{
			if (array[array_row_index] == array[array_col_index])
				return (1);
			array_col_index++;
		}
		array_row_index++;
	}
	return (0);
}
