/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliao-tr <aliao-tr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:08:25 by aliao-tr          #+#    #+#             */
/*   Updated: 2026/07/15 16:04:08 by aliao-tr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free(char **str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**ft_splitstr(char **new_str, char *s, char c, size_t nbr_words)
{
	size_t	i;
	size_t	j;
	char	*start;

	i = 0;
	j = 0;
	while (i < nbr_words)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		start = &s[j];
		while (s[j] != '\0' && s[j] != c)
			j++;
		new_str[i] = ft_substr(start, 0, &s[j] - start);
		if (new_str[i] == NULL)
			return (ft_free(new_str, i));
		i++;
	}
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	int		nbr_words;

	nbr_words = ft_count_words(s, c);
	new_str = ft_calloc(nbr_words + 1, sizeof(char *));
	if (new_str == NULL)
		return (NULL);
	new_str = ft_splitstr(new_str, (char *)s, c, nbr_words);
	return (new_str);
}
