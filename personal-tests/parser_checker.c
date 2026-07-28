/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:12:43 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/28 13:02:51 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ft_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all(char **str, int *numbers)
{
	if (str)
		free_ft_split(str);
	if (numbers)
		free(numbers);
}

void	exit_program(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	count_numbers(int argc, char **argv)
{
	char	**str;
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			count++;
			j++;
		}
		free_ft_split(str);
		i++;
	}
	return (count);
}

void	init_flags(int *flags)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		flags[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		flags[4];
	int		size;

	if (argc < 2)
		return (0);
	init_flags(flags);
	numbers = malloc(sizeof(int) * count_numbers(argc, argv));
	if (!numbers)
		return (1);
	size = parse_args(argc, argv, flags, numbers);
	if (check_flags(flags) || check_duplicates(numbers, size))
	{
		free(numbers);
		printf("check y dup");
		exit_program();
	}
	ft_new_stack(numbers, get_flag(flags));
	return (0);
}
