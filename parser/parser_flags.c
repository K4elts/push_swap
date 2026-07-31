/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:52:08 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/31 11:33:39 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief checks argument and splits the argument
/// @param argc number of arguments
/// @param argv value of arguments
/// @param flags array for flags
/// @param numbers array of numbers
/// @return size - size of array of numbers
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
		if (!str)
			return (0);
		check_nbr_or_flag(str, flags, numbers, &size);
		free_ft_split(str);
		i++;
	}
	return (size);
}

/// @brief check which type of flag is
/// @param str string of the argument
/// @return number of the strategy
int	check_flag_type(char *str)
{
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (STRAT_SIMPLE);
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (STRAT_MEDIUM);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (STRAT_COMPLEX);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (STRAT_ADAPTATIVE);
	if (ft_strncmp(str, "--bench", 8) == 0)
		return (BENCH);
	return (-1);
}

/// @brief checks which flag is > 0
/// @param flags array of flags
/// @return 
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

/// @brief returns the correspondent flag
/// @param flags array of flags
/// @return number of the strategy
int	get_flag(int *flags)
{
	if (flags[STRAT_SIMPLE])
		return (STRAT_SIMPLE);
	if (flags[STRAT_MEDIUM])
		return (STRAT_MEDIUM);
	if (flags[STRAT_COMPLEX])
		return (STRAT_COMPLEX);
	if (flags[STRAT_ADAPTATIVE])
		return (STRAT_ADAPTATIVE);
	return (STRAT_ADAPTATIVE);
}

/// @brief check if there is bench as flag
/// @param argc number of arguments
/// @param argv value of argument
/// @return if there is bench or not
int	check_bench(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}
