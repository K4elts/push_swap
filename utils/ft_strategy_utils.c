/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:49:24 by jgilaber          #+#    #+#             */
/*   Updated: 2026/07/21 20:24:32 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strategy.h"//incorrecto, aqui no va la funcion ft_get_sqrt, no tiene nada que ver son estrategias, sino con operaciones auxiliares de cualquier tipo.

int	ft_get_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_get_sqrt_exacto(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while ((i + 1) <= nb / (i + 1))
		i++;
	return (i);
}