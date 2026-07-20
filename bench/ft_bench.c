/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:43:25 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/16 20:44:32 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

/* El modo benchmark (--bench) es opcional, y mostrará tras la ordenación lo siguiente:
◦ El índice de desorden ( % con dos decimales).
◦ El nombre de la estrategia usada y su clase de complejidad teórica.
◦ El número total de operaciones empleadas.
◦ El número de operaciones de cada tipo (sa, sb, ss, pa, pb, ra, rb, rr, rra,
rrb, rrr) empleadas durante la ordenación.
La salida del modo benchmark debe enviarse a la salida stderr y solo se mostrará
cuando la flag esté presente.

Ejemplo:
$>shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
OK
$> cat bench.txt
[bench] disorder: 49.93%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 7997
[bench] sa: 0  sb: 0  ss: 0  pa: 500  pb: 500
[bench] ra: 4840  rb: 1098  rr: 0  rra: 0  rrb: 1059  rrr: 0
*/
void	ft_show_disorder(t_stack **s)
{
	// es posible que todo esto pueda ser sustituido por la llamada a la funcion -> ft_compute_disorder(t_stack **s) para obtener como float el disorder.
	// Ejemplos: 9999(99.99%), 4993(49.93%), 359(03.59%), 27(00.27%), 6(00.06%)
	ft_printf("[bench] disorder: ");
	// Si tenemos 4 digitos de longitud en (*s)->disorder, entonces cogemos los 2 primeros, los mostramos, luego el . y luego los otros 2 restantes.
	if ((*s)->disorder > 999)
	{}
	else if ((*s)->disorder > 99)
	{}
	else if ((*s)->disorder > 9)
	{}
	else
	{}
	// Mostramos los caracteres finales.
	ft_printchar('%');
	ft_printchar('\n');
}
/// @brief Funcion que muestra el mensaje correspndiente a la estrategia utilizada.
/// @param s
void	ft_show_strategy(t_stack **s)
{
	/*while (condition)
	{
		// Mientras que strategy_used sea distinto de algun tipo de elemento en t_strategy, e bucle se sigue ejecutando.
	}*/
	ft_printf("[bench] strategy: ");
	if ((*s)->strategy_used == STRAT_SIMPLE)
		ft_printf(STRAT_SIMPLE_BENCH_MSG);
	else if ((*s)->strategy_used == STRAT_MEDIUM)
		ft_printf(STRAT_MEDIUM_BENCH_MSG);
	else if ((*s)->strategy_used == STRAT_COMPLEX)
		ft_printf(STRAT_COMPLEX_BENCH_MSG);
	else
	{
		if ((*s)->disorder < 0.2)
			ft_printf(STRAT_ADAPTATIVE_EASY_BENCH_MSG);
		else if ((*s)->disorder >= 0.5)
			ft_printf(STRAT_ADAPTATIVE_COMPLEX_BENCH_MSG);
		else
			ft_printf(STRAT_ADAPTATIVE_MEDIUM_BENCH_MSG);
	}
}

/// @brief Funcion que muestra el numero total de operaciones realizadas.
/// de operaciones realizadas escritas en un fichero en /tmp/*
/// @param ops_count Array de enteros con el numero de operaciones de cada tipo.
void	ft_show_total_operations_count(int *ops_count)
{
	ft_printf("[bench] total_ops: %d\n", ops_count[OP_TOTAL]);
}

/// @brief Funcion que 
/// @param ops_count Array de enteros con el numero de operaciones de cada tipo.
void	ft_show_total_operation_type_count(int *ops_count)
{

}

/// @brief Function that shows on stderr the benchmark
/// @param s Puntero a un stack(t_stack)
void	ft_show_benchmark(t_stack **s, int *ops_count)
{
	ft_show_disorder(s);
	ft_show_strategy(s);
	ft_show_total_operations_count(ops_count);
	ft_show_total_operation_type_count(ops_count);
}
