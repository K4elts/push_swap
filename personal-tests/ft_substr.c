/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:42:28 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/20 14:37:53 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;
	size_t	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
