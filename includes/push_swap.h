/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:30:56 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/11 22:48:02 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "stacklib.h"

typedef enum e_push_swap_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTATIVE
}	t_push_swap_strategy;

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
}	t_e_operations;
/* int op_count[OP_TOTAL] = {0};
Uso de la variable anterior en un fichero .c ->
    op_count[OP_SA]++;
    op_count[OP_SB]++;
    op_count[OP_SS]++;
    op_count[OP_PA]++;
    op_count[OP_PB]++;
    op_count[OP_RA]++;
    op_count[OP_RB]++;
    op_count[OP_RR]++;
    op_count[OP_RRA]++;
    op_count[OP_RRB]++;
    op_count[OP_RRR]++;
*/

typedef struct s_push_swap_operations
{
	void	(*pa)(t_stack **a);
	void	(*pb)(t_stack **b);
	void	(*sa)(t_stack **a);
	void	(*sb)(t_stack **b);
	void	(*ss)(t_stack **a, t_stack **b);
	void	(*ra)(t_stack **a);
	void	(*rb)(t_stack **b);
	void	(*rr)(t_stack **a, t_stack **b);
	void	(*rra)(t_stack **a);
	void	(*rrb)(t_stack **b);
	void	(*rrr)(t_stack **a, t_stack **b);
}	t_push_swap_operations;
// push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
//rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
//rev-rot
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif