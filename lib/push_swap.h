/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:30:56 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/31 17:07:11 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>//write, posible read
# include <stdlib.h>//malloc, free
# include <limits.h>//INT_MAX, INT_MIN
# include <stdio.h>//printf, eliminar despues
# include "stacklib.h"
# include "libft.h"

typedef struct s_push_swap_ops_data
{
	t_stack	**a;
	t_stack	**b;
	int		*operations_count;
}	t_push_swap_ops_data;

/// ESTO PUEDE SER USADO EN fT_do_op(),
///para eso habria que limpiar la linea leida para quitar
///'\n' de la operacion leida -> "pa\n"
/// @deprecated
typedef struct s_push_swap_operations
{
	void	(*pa)(t_push_swap_ops_data *operations_data);
	void	(*pb)(t_push_swap_ops_data *operations_data);
	void	(*sa)(t_stack **a, int *operations_count);
	void	(*sb)(t_stack **b, int *operations_count);
	void	(*ss)(t_push_swap_ops_data *operations_data);
	void	(*ra)(t_stack **a, int *operations_count);
	void	(*rb)(t_stack **b, int *operations_count);
	void	(*rr)(t_push_swap_ops_data *operations_data);
	void	(*rra)(t_stack **a, int *operations_count);
	void	(*rrb)(t_stack **b, int *operations_count);
	void	(*rrr)(t_push_swap_ops_data *operations_data);
}	t_push_swap_operations;

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

//OPERATIONS
void	pa(t_push_swap_ops_data *operations_data);
void	pb(t_push_swap_ops_data *operations_data);
void	sa(t_stack **a, int *operations_count, int show_op);
void	sb(t_stack **b, int *operations_count, int show_op);
void	ss(t_push_swap_ops_data *operations_data);
void	ra(t_stack **a, int *operations_count, int show_op);
void	rb(t_stack **b, int *operations_count, int show_op);
void	rr(t_push_swap_ops_data *operations_data);
void	rra(t_stack **a, int *operations_count, int show_op);
void	rrb(t_stack **b, int *operations_count, int show_op);
void	rrr(t_push_swap_ops_data *operations_data);

//void	ft_do_op(t_push_swap_ops_data *operations_data, char *operation);//revisar
double	ft_do_disorder(t_stack *s);
void	ft_show_benchmark(t_stack **s, int *ops_count);
int		ft_check_if_argv_has_only_int_numbers(int *array);//eliminar, ya la hizo andres
int		ft_check_if_argv_has_duplicated_values(int *array);//eliminar, ya la hizo andres

// SMALL-STRATEGY
void	sort_two(t_push_swap_ops_data *operations_data);
void	sort_three(t_push_swap_ops_data *operations_data);
void	sort_four(t_push_swap_ops_data *operations_data);//X
void	sort_five(t_push_swap_ops_data *operations_data);//X
size_t	get_index_pos(t_push_swap_ops_data *operations_data, size_t index);
void	move_index_to_top(t_push_swap_ops_data *operations_data, size_t index);

// PARSER
int		parse_args(int argc, char **argv, int *flags, int *numbers);
int		check_flag_type(char *str);
int		check_flags(int *flags);
int		get_flag(int *flags);
int		check_bench(int argc, char **argv);
int		*do_parser(int argc, char **argv, int *flags);
void	init_flags(int *flags);
void	free_all(char **str, int *numbers);
void	free_ft_split(char **str);
int		count_numbers(int argc, char **argv);
int		is_valid(char *str);
int		check_duplicates(int *numbers, int size);
void	save_number(char *str, int *numbers, int *size, char **split_str);
void	check_nbr_or_flag(char **str, int *flags, int *numbers, int *size);
void	exit_program(void);

void	ft_sort_small(t_push_swap_ops_data *operations_data);

#endif