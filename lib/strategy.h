/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:30:56 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/13 21:27:27 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRATEGY_H
# define STRATEGY_H

typedef struct s_stack	t_stack;

# define STRAT_SIMPLE_BENCH_MSG    "Simple / O(n2)"
# define STRAT_MEDIUM_BENCH_MSG    "Medium / O(n√n)"
# define STRAT_COMPLEX_BENCH_MSG   "Complex / O(n log n)"
# define STRAT_ADAPTATIVE_EASY_BENCH_MSG "Adaptative / O(n2)"
# define STRAT_ADAPTATIVE_MEDIUM_BENCH_MSG   "Adaptive / O(n√n)"
# define STRAT_ADAPTATIVE_COMPLEX_BENCH_MSG   "Adaptive / O(n log n)"

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTATIVE,
	STRAT_COUNT
}	t_strategy;

void	ft_exec_strat_dispatch(t_stack **a, t_stack **b, int *ops_count);
void	ft_do_simple_strategy(t_stack **a, t_stack **b, int *ops_count);
void	ft_do_medium_strategy(t_stack **a, t_stack **b, int *ops_count);
void	ft_do_complex_strategy(t_stack **a, t_stack **b, int *ops_count);
void	ft_do_adaptative_strategy(t_stack **a, t_stack **b, int *ops_count);

#endif