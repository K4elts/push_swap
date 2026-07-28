/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:30:24 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/28 13:02:29 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_nbr_or_flag(char **str, int *flags, int *numbers, int *size)
{
	int	i;
	int	type;

	i = 0;
	while (str[i])
	{
		type = check_flag_type(str[i]);
		if (type != -1)
			flags[type]++;
		else
			save_number(str[i], numbers, size, str);
		i++;
	}
}

void	exit_program(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	save_number(char *str, int *numbers, int *size, char **split_str)
{
	long	nbr;

	if (!is_valid(str))
	{
		free_all(split_str, numbers);
		exit_program();
	}
	nbr = ft_atoi(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
	{
		free_all(split_str, numbers);
		exit_program();
	}
	numbers[*size] = (int)nbr;
	(*size)++;
}

int	check_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
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
