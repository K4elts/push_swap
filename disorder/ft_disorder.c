/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:09:00 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/13 20:17:32 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_compute_disorder(t_stack **s)
{
	size_t	stack_row;
	size_t	stack_col;
	int		total_pairs;
	float	mistakes;

	mistakes = 0;
	total_pairs = 0;
	stack_row = 0;
	while (stack_row < ((*s)->size -1))
	{
		stack_col = stack_row + 1;
		while (stack_col < ((*s)->size -1))
		{
			total_pairs += 1;
			if (s[stack_row] > s[stack_col])
				mistakes += 1;
			stack_col++;
		}
		stack_row++;
	}
	return (mistakes / total_pairs);
}
