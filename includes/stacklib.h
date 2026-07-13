/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:45:33 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/11 22:47:45 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKLIB_H
# define STACKLIB_H

# include <stddef.h>

typedef struct s_stack_node
{
	int					data;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	size_t			size;
}	t_stack;


/*t_stack	*stack_create(void);
int		stack_push(t_stack *stack, void *data);
void	*stack_pop(t_stack *stack);
void	*stack_peek(t_stack *stack);
int		stack_is_empty(t_stack *stack);*/
t_stack_node	*ft_stack_last(t_stack *stack);

#endif