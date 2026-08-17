/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:43:25 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/31 11:42:52 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Function that show the information of the disorder.
/// La operacion +0.5f es el truco correcto para redondear a dos decimales
/// cuando conviertes el float a centésimas enteras.
/// @param stack 
/// @return Nothing
/// @authors jgilabert & aliao-tr
static void	ft_show_disorder(t_stack *stack)
{
	long	value;
	long	ent;
	long	dec;

	value = (long)(stack->disorder * 10000.0f + 0.5f);
	ent = value / 100;
	dec = value % 100;
	ft_putstr_fd("[bench] disorder: ", STDERR_FILENO);
	if (ent < 10)
		ft_putchar_fd('0', STDERR_FILENO);
	ft_putnbr_fd(ent, STDERR_FILENO);
	ft_putchar_fd('.', STDERR_FILENO);
	if (dec < 10)
		ft_putchar_fd('0', STDERR_FILENO);
	ft_putnbr_fd(dec, STDERR_FILENO);
	ft_putendl_fd("%", STDERR_FILENO);
}

/// @brief Function that shows the message of the used strategy.
/// @param stack The stack to show the strategy.
/// @return Nothing
/// @authors jgilabert & aliao-tr
static void	ft_show_strategy(t_stack *stack)
{
	int	strategy_used;

	strategy_used = stack->strategy_used;
	ft_putstr_fd("[bench] strategy: ", STDERR_FILENO);
	if (strategy_used == STRAT_SIMPLE)
		ft_putendl_fd(STRAT_SIMPLE_BENCH_MSG, STDERR_FILENO);
	else if (strategy_used == STRAT_MEDIUM)
		ft_putendl_fd(STRAT_MEDIUM_BENCH_MSG, STDERR_FILENO);
	else if (strategy_used == STRAT_COMPLEX)
		ft_putendl_fd(STRAT_COMPLEX_BENCH_MSG, STDERR_FILENO);
	else if (stack->disorder < 0.2)
		ft_putendl_fd(STRAT_ADAPTIVE_SIMPLE_BENCH_MSG, STDERR_FILENO);
	else if (stack->disorder >= 0.5)
		ft_putendl_fd(STRAT_ADAPTIVE_COMPLEX_BENCH_MSG, STDERR_FILENO);
	else
		ft_putendl_fd(STRAT_ADAPTIVE_MEDIUM_BENCH_MSG, STDERR_FILENO);
}

/// @brief Function that show the total operation of each type.
/// @param ops_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
/// @authors jgilaber & aliao-tr
static void	ft_show_total_operations_count(int *ops_count)
{
	ft_putstr_fd("[bench] total_ops: ", STDERR_FILENO);
	ft_putendl_fd(ft_itoa(ops_count[OP_TOTAL]), STDERR_FILENO);
	ft_putstr_fd("[bench] sa: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_SA], STDERR_FILENO);
	ft_putstr_fd("  sb: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_SB], STDERR_FILENO);
	ft_putstr_fd("  ss: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_SS], STDERR_FILENO);
	ft_putstr_fd("  pa: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_PA], STDERR_FILENO);
	ft_putstr_fd("  pb: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_PB], STDERR_FILENO);
	write(STDERR_FILENO, "\n", 2);
	ft_putstr_fd("[bench] ra: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_RA], STDERR_FILENO);
	ft_putstr_fd("  rb: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_RB], STDERR_FILENO);
	ft_putstr_fd("  rr: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_RR], STDERR_FILENO);
	ft_putstr_fd("  rra: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_RRA], STDERR_FILENO);
	ft_putstr_fd("  rrb: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_RRB], STDERR_FILENO);
	ft_putstr_fd("  rrr: ", STDERR_FILENO);
	ft_putnbr_fd(ops_count[OP_RRR], STDERR_FILENO);
}

/// @brief Function that shows on stderr the benchmark.
/// @param stack The stack to show the benchmark
/// @param ops_count Int-Array that contains
/// the count of all type of operations.
/// @return Nothing
/// @authors jgilabert & aliao-tr
void	ft_show_benchmark(t_stack *stack, int *ops_count)
{
	ft_show_disorder(stack);
	ft_show_strategy(stack);
	ft_show_total_operations_count(ops_count);
}

/// @brief check if there is bench as flag
/// @param argc number of arguments
/// @param argv value of argument
/// @return if there is bench or not
int	ft_check_benchmark(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}