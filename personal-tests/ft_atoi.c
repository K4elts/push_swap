/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:52:51 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/15 13:26:46 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}
