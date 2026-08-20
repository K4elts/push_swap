/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:30:56 by jgilaber          #+#    #+#             */
/*   Updated: 2026/08/19 19:42:32 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>//write, posible read
# include <stdlib.h>//malloc, free
# include <limits.h>//INT_MAX, INT_MIN
# include <stdio.h>//printf, eliminar despues
# include <fcntl.h>//open
# include <stdarg.h>//
# include "push_swap_helpers.h"
# include "stacklib.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FD_CHECKER_IN 666
# define FD_CHECKER_OUT 666
# define HIDE_PUSH_SWAP_OPERATION 0
# define SHOW_PUSH_SWAP_OPERATION 1

typedef struct s_push_swap_ops_data
{
	t_stack	**a;
	t_stack	**b;
	int		*operations_count;
	int		show_op;
}	t_push_swap_ops_data;

typedef enum e_push_swap_operations_type
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_TOTAL
}	t_push_swap_operations_type;

void	pa(t_push_swap_ops_data *operations_data);
void	pb(t_push_swap_ops_data *operations_data);
void	sa(t_stack **stack_a, int *operations_count, int show_op);
void	sb(t_stack **stack_b, int *operations_count, int show_op);
void	ss(t_push_swap_ops_data *operations_data);
void	ra(t_stack **stack_a, int *operations_count, int show_op);
void	rb(t_stack **stack_b, int *operations_count, int show_op);
void	rr(t_push_swap_ops_data *operations_data);
void	rra(t_stack **stack_a, int *operations_count, int show_op);
void	rrb(t_stack **stack_b, int *operations_count, int show_op);
void	rrr(t_push_swap_ops_data *operations_data);
void	ft_show_push_swap_op(char *operation, int show_op);
void	ft_exit_program(char *exit_message, int exit_code);
double	ft_get_disorder(t_stack **stack);
int		ft_check_numbers_order(int *numbers, size_t numbers_size);
int		ft_check_benchmark(int argc, char **argv);
void	ft_show_benchmark(t_stack *stack, int *ops_count);
int		ft_count_numbers(int argc, char **argv);
int		ft_parse_args(int argc, char **argv, int *flags, int *numbers);
void	ft_free_split(char **str);
void	ft_free_all(char **str, int *numbers);
void	ft_save_numbr(char *str, char **splt_str, int *nbrs, size_t *nbrs_size);
int		ft_check_duplicates_numbers(int *numbers, int size);
void	ft_check_nbr_or_flag(char **str, int *flags, int *nmbrs, size_t *size);
int		ft_check_strategy_flags(int *flags);
int		ft_get_strategy_flag(int *flags);
void	ft_push_swap_checker(int argc, char **argv);
int		ft_read_operations(t_push_swap_ops_data *operations_data, int fd);

#endif