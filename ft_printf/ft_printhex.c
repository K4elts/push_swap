/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:33:03 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/06/19 13:02:44 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long nbr, char format)
{
	long			count;
	char			*base;
	unsigned int	base_len;

	base_len = 16;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (nbr >= base_len)
		count = ft_printhex((nbr / base_len), format);
	count += ft_printchar(base[nbr % base_len]);
	return (count);
}
