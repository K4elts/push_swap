/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:30:56 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/16 19:11:21 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>//write, posible read
# include <stdlib.h>//malloc, free
# include "stacklib.h"

typedef enum e_operations
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
}	t_operations;

// ESTO PUEDE SER USADO EN fT_do_op(), para eso habria que limpiar la linea leida para quitar '\n' de la operacion leida -> "pa\n"
typedef struct s_push_swap_operations
{
	void	(*pa)(t_stack **a, t_stack **b, int *operations_count);
	void	(*pb)(t_stack **a, t_stack **b, int *operations_count);
	void	(*sa)(t_stack **a, int *operations_count);
	void	(*sb)(t_stack **b, int *operations_count);
	void	(*ss)(t_stack **a, t_stack **b, int *operations_count);
	void	(*ra)(t_stack **a, int *operations_count);
	void	(*rb)(t_stack **b, int *operations_count);
	void	(*rr)(t_stack **a, t_stack **b, int *operations_count);
	void	(*rra)(t_stack **a, int *operations_count);
	void	(*rrb)(t_stack **b, int *operations_count);
	void	(*rrr)(t_stack **a, t_stack **b, int *operations_count);
}	t_push_swap_operations;

void	pa(t_stack **a, t_stack **b, int *operations_count);
void	pb(t_stack **a, t_stack **b, int *operations_count);
void	sa(t_stack **a, int *operations_count);
void	sb(t_stack **b, int *operations_count);
void	ss(t_stack **a, t_stack **b, int *operations_count);
void	ra(t_stack **a, int *operations_count);
void	rb(t_stack **b, int *operations_count);
void	rr(t_stack **a, t_stack **b, int *operations_count);
void	rra(t_stack **a, int *operations_count);
void	rrb(t_stack **b, int *operations_count);
void	rrr(t_stack **a, t_stack **b, int *operations_count);

void	ft_show_benchmark(t_stack **s, int *ops_count);
float	ft_compute_disorder(t_stack **s);
// añadir funciones de ft_errors.c

#endif