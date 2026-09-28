/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 02:00:53 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/28 15:30:10 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] && s2[index] && index < n)
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}

int	ft_isdigit(char *character)
{
	size_t	index;

	index = 0;
	while (character[index])
	{
		if (character[index] < '0' || character[index] > '9')
			return (0);
		index++;
	}
	return (1);
}
