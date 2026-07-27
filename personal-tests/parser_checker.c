/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:12:43 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/27 18:13:46 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_program(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i = 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_flags(int *flags)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (flags[i] > 0)
			count++;
		i++;
	}
	return (count > 1);
}

void	free_all(char **str, int *numbers)
{
	if (str)
		free_split(str);
	if (numbers)
		free(numbers);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	save_number(char *str, int *numbers, int size, char **split_str)
{
	long	nbr;

	if (!is_valid(str))
		free_all(split_str, numbers);
}

int	check_flag_type(char *str)
{
	if (ft_strcmp(str, "--simple"))
		return (0);
	if (ft_strcmp(str, "--medium"))
		return (1);
	if (ft_strcmp(str, "--complex"))
		return (2);
	if (ft_strcmp(str, "--adaptive"))
		return (3);
	return (-1);
}

void	check_nbr_or_flag(char **str, int *flags, int *numbers, int *size)
{
	int	i;
	int	type;

	i = 0;
	while (!str[i])
	{
		type = check_flag_type(str[i]);
		if (type != -1)
			flags[type]++;
		else
			save_number(str[i], numbers, size, str);
		i++;
	}
}

int	parse_args(int argc, char **argv, int *flags, int *numbers)
{
	char	**str;
	int		i;
	int		size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		check_nbr_or_flag(str, flags, numbers, &size);
		free_ft_split(str);
		i++;
	}
	return (size);
}

void	init_flags(int *flags)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		flags[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		*numbers;
	int		flags[4];
	int		size;

	if (argc < 2)
		return (0);
	init_flags(flags);
	numbers = malloc(sizeof(int) * INT_MAX);
	if (!numbers)
		return (1);
	size = parse_args(argc, argv, flags, numbers);
	if (check_flags(flags) || check_duplicates(numbers, size))
	{
		free(numbers);
		exit_program();
	}
	ft_new_stack(numbers /*pasar el numero de la estrategia a usar*/);
	return (0);
}

/*
static int	check_bench(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench"))
			return (1);
		i++;
	}
	return (0);
}

static int	get_flag(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (0);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (2);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (3);
	return (-1);
}

long	ft_atol(int *nums)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	if (nums[i] == '+' || nums[i] == '-')
	{
		if (nums[i] == '-')
			sign *= -1;
	}
	while (!nums[i])
		nbr = (nbr * 10) + (nums[i++] - '0');
	return (nbr);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	save_number(char *str, int *nums, int *count)
{
	long	nbr;

	if (!is_valid(str))
	{
		printf("Error");
	}
	nbr = ft_atol(nums);
	if (nbr < INT_MIN || nbr > INT_MAX)
	{
		printf("Error");
	}
	nums[*count] = (int)nbr;
	(*count)++;
}

void	check_flag_or_number(char **str, int *nums, int *count, int *flags)
{
	int	i;
	int	flag;

	i = 0;
	while (str[i] != NULL)
	{
		flag = get_flag(str[i]);
		if (flag != -1)
			flags[flag]++;
		else
			save_number(str[i], nums, count);
		i++;
	}
}

int	parse_args(int argc, char **argv, int *nums, int *flags)
{
	char	**str;
	int		i;
	int		count;

	i = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		check_flag_or_number(str, nums, &count, flags);
		i++;
	}
	return (count);
}

t_stack_node	*new_node(int content)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack_node	*create_list(int *nums, int size)
{
	t_stack_node	*node;
	t_stack_node	*top;
	t_stack_node	*last;
	int				i;

	i = 0;
	while (i < size)
	{
		node = new_node(nums[i]);
		if (!node)
			return (NULL);
		if (top == NULL)
			top = node;
		else
		{
			last->next = node;
			node->prev = last;
		}
		last = node;
		i++;
	}
	return (top);
}

int	conflict_flags(int *flags)
{
	int	flag_count;
	int	i;

	flag_count = 0;
	i = 0;
	while (i < 4)
	{
		if (flags[i] > 0)
			flag_count++;
		i++;
	}
	return (flag_count > 1);
}

/nt	check_duplicates(t_stack **stack_a, int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		*nums;
	int		size;
	int		flags[5];

	if (argc < 2)
		return (printf("Error"), 0);
	stack_a = malloc(sizeof(t_stack *));
	if (!stack_a)
		return (1);
	*stack_a = malloc(sizeof(t_stack));
	if (!*stack_a)
		return (1);
	if (check_bench(argc, argv) == 1)
		printf("Hacer bench");
	nums = malloc(sizeof(int) * INT_MAX);
	if (!nums)
		return (1);
	size = parse_args(argc, argv, nums, flags);
	if (conflict_flags(flags))
		return (printf("Error"), 0);
	(*stack_a)->top = create_list(nums, size);
	//check_duplicates(stack_a, nums, size);
	free(nums);
	if (!stack_a)
		return (printf("Error"), 0);
	stack_b = NULL;
	while ((*stack_a)->top)
	{
		printf("%d", (*stack_a)->top->data);
		(*stack_a)->top = (*stack_a)->top->next;
	}
	
	return (0);
}
*/