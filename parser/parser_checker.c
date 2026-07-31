/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:12:43 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/31 11:50:03 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/// @brief does free
/// @param str characters from split
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

/// @brief does free
/// @param str characters from split
/// @param numbers array of numbers
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

/// @brief initialize flags to 0
/// @param flags int-array for flags
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

int	*do_parser(int argc, char **argv, int *flags)
{
	int	size;
	int	*numbers;
	int	number_counter;

	if (argc < 2)
		exit_program();
	number_counter = count_numbers(argc, argv);
	if (number_counter <= 0)
		exit_program();
	numbers = malloc(sizeof(int) * number_counter);
	if (!numbers)
		exit_program();
	init_flags(flags);
	size = parse_args(argc, argv, flags, numbers);
	if (check_flags(flags) || check_duplicates(numbers, size))
	{
		free(numbers);
		exit_program();
	}
	return (numbers);
}
