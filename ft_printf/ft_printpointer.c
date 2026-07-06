/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:22:28 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/06/19 12:03:41 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_printstr_fd("(nil)", 1));
	count = ft_printstr_fd("0x", 1);
	count += ft_printhex((unsigned long)ptr, 'p');
	return (count);
}
