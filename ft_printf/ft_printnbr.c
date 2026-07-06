/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:31:54 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/06/19 13:41:55 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_printchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count += ft_printnbr(nbr / 10);
	}
	count += ft_printchar((nbr % 10) + '0');
	return (count);
}

int	ft_printunsignednbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_printunsignednbr(nbr / 10);
	}
	count += ft_printchar((nbr % 10) + '0');
	return (count);
}
