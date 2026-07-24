



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
