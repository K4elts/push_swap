/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:30:24 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/30 13:37:36 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief redirects if argument is a flag or a number
/// @param str string from split
/// @param flags array of flags
/// @param numbers array of numbers
/// @param size size of numbers array
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

/// @brief saves the number into the numbers array
/// @param str 
/// @param numbers array of numbers
/// @param size size of numbers
/// @param split_str 
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

/// @brief checks if there is a duplicated numbers
/// @param numbers array of numbers
/// @param size size of numbers array
/// @return 0 if theres no duplicates and 1 if there is duplicates
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

/// @brief checks if the number if valid
/// @param str number
/// @return 0 if number is valid, 1 if not
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

/// @brief counts how many numbers there are
/// @param argc numbers of arguments
/// @param argv value of arguments
/// @return how many numbers there are
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
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
			continue ;
		}
		str = ft_split(argv[i], ' ');
		if (!str)
			return (0);
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
