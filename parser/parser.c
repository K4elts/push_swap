/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:24:53 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/20 15:11:18 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void	sortarray(int *array)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < sizeof(array) - 1)
	{
		while (j < sizeof(array) - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}*/

static int	check_duplicate_num(int *array, int array_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_len)
	{
		j = i + 1;
		while (j < array_len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	*fill_array(int argc, char **argv)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * argc - 1);
	if (!array)
		return (NULL);
	i = 0;
	if (argc > 2)
	{
		while (i < argc - 1)
		{
			array[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	return (array);
}
static int	count_size(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
}
static int	*ft_do_one_argument(char ** argv)
{
	char	**nums;
	int		size;
	int		*array;
	int		i;
	int		j;

	nums = ft_split(argv[1], ' ');
	if (!nums)
		return (NULL);
	size = count_size(nums);
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		array[i] = ft_atoi(nums[i]);
		i++;
	}
	return (array);
}
static int	array_len(int *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	//t_stack	**stack_a;
	int		*array;
	int		array_size;
	int		i;
	int		isduplicate;

	if (argc < 2)
		return (printf("Error"), -1);
	if (argc == 2)
	{
		printf("argc 2\n");
		array = ft_do_one_argument(argv);
	}
	else
		array = fill_array(argc, argv);
	array_size = array_len(array);
	isduplicate = check_duplicate_num(array, array_size);
	if (isduplicate == 1)
	{
		printf("Numero duplicado");
		return (0);
	}
	//sortarray(array);
	i = 0;
	while (array[i])
	{
		printf("valor: %d\n", array[i]);
		i++;
	}
	return (0);
}
