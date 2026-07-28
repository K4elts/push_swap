/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:52:08 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/28 13:02:32 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_flag_type(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (STRAT_SIMPLE);
	if (ft_strcmp(str, "--medium") == 0)
		return (STRAT_MEDIUM);
	if (ft_strcmp(str, "--complex") == 0)
		return (STRAT_COMPLEX);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (STRAT_ADAPTATIVE);
	return (-1);
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
