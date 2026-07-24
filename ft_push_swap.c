/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:18:13 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/20 22:10:02 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

/// @brief Return sacado de -> ft_exec_strat_dispatch() ya que no devuelve nada, ops_count lo recibe en vez de crearlo.
// El índice de desorden se calculará antes de hacer ningún movimiento.
// Establecemmos el valor de disorder del stack_a al obtenido de ft_do_compute_disorder(t_stack **s)
/// @return operations_count Int-Array that contains
/// the count of all type of operations.
void	ft_push_swap(t_stack **a, t_stack **b, int **nbr_list)
{
	int	*operations_count;

	operations_count = malloc(sizeof(int) * OP_TOTAL);
	ft_exec_strat_dispatch(a, b, operations_count);
}

//en main ahora: comprueba si hay uno o mas arguentos. Si es solo uno hace split y los guarda en un array, si son mas de 2 argumentos los guarda directamente.
//tambien comprueba si hay numeros duplicados en el array
//Hay que comprobar que solo haya numeros, no haya numeros duplicados(HECHO), si introduce varios signos + o -
//Si cada numero es un argumentos se guardan tal cual, ejemplo: ./push_swap 5 2 9 -1 (HECHO)
//en caso de que se pasen en un solo argumento, ejemplo: ./push_swap "1 6 -2 54" hacer split para separar los numeros y guardarlos. (HECHO)
//en cuanto al indice habrá que hacer algun tipo de indexacion para que cada nodo tenga guardado el indice que le corresponda:
//IDEA??: guardar en array -> con copia ordenada del array -> comparar los dos array para saber el indice que deberia tener el numero con la lista ordenada
/*
//checks if there is a duplicate number
static int	ft_check_duplicated_values(int *array, int array_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_len)
	{
		j = i + 1;
		while (j < array_len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
//fills an array with the numbers (each number is an argument)
static int	*fill_array(int argc, char **argv)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * argc - 1);
	if (!array)
		return (NULL);
	i = 0;
	if (argc > 2)
	{
		while (i < argc - 1)
		{
			array[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	return (array);
}
//array_len for split, un solo argumento //supongo que se podrá juntar con array_len
static int	count_size(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
}
//numbers are in one argument, do split and adds it to the array
static int	*ft_do_one_argument(char ** argv)
{
	char	**nums;
	int		size;
	int		*array;
	int		i;
	int		j;

	nums = ft_split(argv[1], ' ');
	if (!nums)
		return (NULL);
	size = count_size(nums);
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		array[i] = ft_atoi(nums[i]);
		i++;
	}
	return (array);
}
//array_len //para fill_array, varios argumentos
static int	array_len(int *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	i	//t_stack	**stack_a;
	int		*array;
	int		array_size;
	int		i;
	int		isduplicate;

	if (argc < 2)
		return (printf("Error"), -1);
	if (argc == 2)
		array = ft_do_one_argument(argv);
	else
		array = fill_array(argc, argv);
	array_size = array_len(array);
	isduplicate = ft_check_duplicated_values(array, array_size);
	if (isduplicate == 1)
	{
		printf("Numero duplicado");
		return (0);
	}
	//sortarray(array);
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
