/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:20:33 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/06/19 13:27:51 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_printstr_fd(va_arg(args, char *), 1));
	else if (format == 'd' || format == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (format == 'p')
		return (ft_printpointer(va_arg(args, void *)));
	else if (format == 'u')
		return (ft_printunsignednbr(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_printhex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_printchar('%'));
	return (-1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	if (format == NULL)
		return (-1);
	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else if (format[i] == '%')
		{
			i++;
			printed += check_format(format[i], args);
		}
		else
			printed += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (printed);
}
