/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:41 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/19 21:29:52 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t	lit_index;

	if (!little[0])
		return ((char *)big);
	big_index = 0;
	while (big[big_index] && big_index < len)
	{
		lit_index = 0;
		while (big[big_index + lit_index] == little[lit_index]
			&& big_index + lit_index < len)
			lit_index++;
		if (!little[lit_index])
			return ((char *)(big + big_index));
		big_index++;
	}
	return (NULL);
}
