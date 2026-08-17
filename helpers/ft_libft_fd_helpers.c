/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_fd_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:32:57 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/22 18:48:20 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief 
/// @param c 
/// @return 
int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

/// @brief 
/// @param c 
/// @param fd 
void	ft_putchar_fd(char c, int fd)
{
    if (!c || fd < 0)
		return ;
	write(fd, &c, sizeof(char));
}

/// @brief 
/// @param s 
/// @param fd 
void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

/// @brief 
/// @param s 
/// @param fd 
void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/// @brief 
/// @param n 
/// @param fd 
void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	if ((!n && n != 0) || fd < 0)
		return ;
	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	write(fd, &c, 1);//ft_putchar_fd(c, fd);
}