/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_aux_gila.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:29:11 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/24 18:29:11 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
static int	ft_do_op(t_stack **a, t_stack **b, char *operation, int *ops_count)
{
	if (ft_strcmp(operation, "pa\n") == 0)
		pa(a, b, ops_count);
	else if (ft_strcmp(operation, "pb\n") == 0)
		pb(a, b, ops_count);
	else if (ft_strcmp(operation, "sa\n") == 0)
		sa(a, ops_count);
	else if (ft_strcmp(operation, "sb\n") == 0)
		sb(b, ops_count);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(a, b, ops_count);
	else if (ft_strcmp(operation, "ra\n") == 0)
		ra(a, ops_count);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rb(b, ops_count);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(a, b, ops_count);
	else if (ft_strcmp(operation, "rra\n") == 0)
		rra(a, ops_count);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		rrb(b, ops_count);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(a, b, ops_count);
	else
		return (1);
}

void ft_read_instructions(t_stack **a, t_stack **b)
{
	char *line;

	line = get_next_line(0);//fd = 2002 por ejemplo
	while (line != NULL)
	{
		ft_do_op(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}*/
