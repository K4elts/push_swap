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

int	main(int argc, char **argv)
{
	int	argv_row;
	int	argv_col;
	int	**nbr_list;

	argv_row = 0;
	nbr_list = malloc((argc - 1) * sizeof(int *));
	if (!nbr_list)
		return (1);
	while ((argc - 1) > 0)
	{
		argv_col = 0;
		nbr_list[argv_row] = malloc((ft_strlen(argv[argv_row]) + 1)//argv[argv_row + 1]
				* sizeof(int));
		while (argv[argv_row])
		{
			while (argv[argv_row][argv_col])
			{
				nbr_list[argv_row][argv_col] = argv[argv_row][argv_col];
				argv_col++;
			}
			argv_row++;
		}
		argc--;
	}
	ft_push_swap(nbr_list);
	return (0);
}


void	ft_exec_strat_dispatch_with_ops_create(t_stack **a, t_stack **b, int *ops_count)
{
	t_strategy_type			strategy_used;
	t_push_swap_ops_data	operations_data;

	if (!(*a)->top || !(*b)->top)
		return ;
	operations_data.a = a;
	operations_data.b = b;
	operations_data.operations_count = ops_count;
	strategy_used = (*a)->strategy_used;
	if (strategy_used == STRAT_SIMPLE)
		ft_do_simple_strategy(&operations_data);
	else if (strategy_used == STRAT_MEDIUM)
		ft_do_medium_strategy(&operations_data);
	else if (strategy_used == STRAT_COMPLEX)
		ft_do_complex_strategy(&operations_data);
	else
		ft_do_adaptative_strategy(&operations_data);
}


/// @deprecated - procedente de ft_do_medium_strategy()
int	ft_get_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/// @deprecated - procedente de ft_do_medium_strategy()
int	ft_get_sqrt_exacto(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while ((i + 1) <= nb / (i + 1))
		i++;
	return (i);
}
