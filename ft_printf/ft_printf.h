/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:35:47 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/06/19 13:08:55 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(char const *format, ...);
int	ft_printchar(char c);
int	ft_printstr_fd(char *s, int fd);
int	ft_printnbr(long nbr);
int	ft_printunsignednbr(unsigned int nbr);
int	ft_printpointer(void *ptr);
int	ft_printhex(unsigned long nbr, char format);

#endif
