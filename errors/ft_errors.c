/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:43:30 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/15 21:40:00 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// UN POSIBLE ERROR ES UNA OPERACION INCORRECTA INTRODUCIDA EN ft_do_op()

/// @brief Muestra un mensaje de error en la salida de error.
/// @param exit_code Exit code
/// @return void Nothing
void ft_putstr_error(int exit_code)
{
    write(2, "Error\n", 6);
    exit(exit_code);
}

/*
En caso de error, deberá mostrar “Error” seguido de un \n en la salida de error
estándar. Algunos de los posibles errores son, por ejemplo: argumentos que no son
enteros, argumentos superiores a un número entero, y/o números duplicados.
*/
/// @brief Devuelve 1 si al menos 1 elemento no es nu numero.
/// @param array Array de enteros con 
/// @return int Devuelve 1 si al menos 1 elemento no es nu numero.
int ft_check_if_argv_has_only_int_numbers(char *array)
{
	int	array_index;

	array_index = 0;
	while (array[array_index])
	{
		if (!ft_isdigit(array[array_index]))
			return (1);
		array_index++;
	}
	return (0);
}

// Devuelve 1 si hay elementos duplicados, ya sean numeros o signos. (Sujeto a cambios/correcciones)
int	ft_check_if_argv_has_duplicated_values(char *array)
{
	int	array_index;
	int	array_index2;

	array_index = 0;
	while (array[array_index])
	{
		array_index2 = array_index + 1;
		while (array[array_index2])
		{
			if (array[array_index] == array[array_index2])
				return (1);
			array_index2++;
		}
		array_index++;
	}
	return (0);
}