/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double_toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 23:32:56 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/03 23:56:33 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_double_fraction(double number, int precision)
{
	char	*result;
	int		index;

	result = malloc(sizeof(char) * (precision + 1));
	if (!result)
		return (NULL);
	number -= (long long)number;
	index = 0;
	while (index < precision)
	{
		number *= 10;
		result[index] = '0' + (int)number;
		number -= (int)number;
		index++;
	}
	result[index] = '\0';
	return (result);
}

char	*ft_dtoa(double number, int precision)
{
	char	*integer;
	char	*fraction;
	char	*result;
	char	*separator;

	integer = ft_itoa((long long)number);
	if (!integer)
		return (NULL);
	fraction = ft_double_fraction(number, precision);
	if (!fraction)
		return (free(integer), NULL);
	separator = ft_strjoin(integer, ".");
	if (!separator)
		return (free(integer), free(fraction), NULL);
	result = ft_strjoin(separator, fraction);
	if (!result)
		return (free(integer), free(fraction), free(separator), NULL);
	free(integer);
	free(fraction);
	free(separator);
	return (result);
}
