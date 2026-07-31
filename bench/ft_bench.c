/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:43:25 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/31 11:42:52 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

/// @brief Function that show the information of the disorder.
/// La operacion +0.5f es el truco correcto para redondear a dos decimales
/// cuando conviertes el float a centésimas enteras.
/// @param s 
/// @return Nothing
static void	ft_show_disorder(t_stack **s)
{
	long	value;
	long	ent;
	long	dec;

	value = (long)((*s)->disorder * 100.0f + 0.5f);
	ent = value / 100;
	dec = value % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	if (ent < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(ent, 2);
	ft_putchar_fd('.', 2);
	if (dec < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec, 2);
	ft_putendl_fd("%", 2);
}

/// @brief Function that shows the message of the used strategy.
/// @param s stack_s
/// @authors jgilabert & aliao-tr
/// @return Nothing
static void	ft_show_strategy(t_stack **s)
{
	if ((*s)->strategy_used == STRAT_SIMPLE)
		ft_putendl_fd(STRAT_SIMPLE_BENCH_MSG, 2);
	else if ((*s)->strategy_used == STRAT_MEDIUM)
		ft_putendl_fd(STRAT_MEDIUM_BENCH_MSG, 2);
	else if ((*s)->strategy_used == STRAT_COMPLEX)
		ft_putendl_fd(STRAT_COMPLEX_BENCH_MSG, 2);
	else
	{
		if ((*s)->disorder < 0.2)
			ft_putendl_fd(STRAT_ADAPTATIVE_SIMPLE_BENCH_MSG, 2);
		else if ((*s)->disorder >= 0.5)
			ft_putendl_fd(STRAT_ADAPTATIVE_COMPLEX_BENCH_MSG, 2);
		else
			ft_putendl_fd(STRAT_ADAPTATIVE_MEDIUM_BENCH_MSG, 2);
	}
}

/// @brief Function that show the total operation of each type.
/// @param ops_count Array de enteros con el numero de operaciones de cada tipo.
static void	ft_show_total_operations_count(int *ops_count)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putstr_fd(ft_itoa(ops_count[OP_SA]), 2);
	//ft_putnbr_fd(ops_count[OP_SA], 2);//version oprimizada sin usar itoa, si esto funciona itoa no hace falta y se puede eliminar ft_itoa.c
	ft_putstr_fd("  sb: ", 2);
	ft_putstr_fd(ft_itoa(ops_count[OP_SB]), 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putstr_fd(ft_itoa(ops_count[OP_SS]), 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putstr_fd(ft_itoa(ops_count[OP_PA]), 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putendl_fd(ft_itoa(ops_count[OP_PB]), 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putstr_fd(ft_itoa(ops_count[OP_RA]), 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putstr_fd(ft_itoa(ops_count[OP_RB]), 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putstr_fd(ft_itoa(ops_count[OP_RR]), 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putstr_fd(ft_itoa(ops_count[OP_RRA]), 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putstr_fd(ft_itoa(ops_count[OP_RRB]), 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putendl_fd(ft_itoa(ops_count[OP_RRR]), 2);
}

/// @brief Function that shows on stderr the benchmark
/// @authors jgilabert & aliao-tr
/// @param s stack_s
/// @return Nothing
void	ft_show_benchmark(t_stack **s, int *ops_count)
{
	ft_show_disorder(s);
	ft_show_strategy(s);
	ft_printf("[bench] total_ops: %d\n", ops_count[OP_TOTAL]);
	ft_show_total_operations_count(ops_count);
}
