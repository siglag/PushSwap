/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 02:00:53 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/01 00:12:00 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
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
	while (index < n && (s1[index] || s2[index]))
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

int	ft_fulldigit(char *character)
{
	size_t	index;

	index = 0;
	while (character[index])
	{
		if ((character[index] < '0' || character[index] > '9')
			&& character[index] != ' '
			&& character[index] != '-'
			&& character[index] != '+')
			return (0);
		index++;
	}
	return (1);
}

int	ft_strcasecmp(char *s1, char *s2)
{
	size_t	index;

	index = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (s1[index] && s2[index])
	{
		if (ft_tolower(s1[index]) != ft_tolower(s2[index]))
			return (s1[index] - s2[index]);
		index++;
	}
	return (s1[index] - s2[index]);
}

char	ft_tolower(char character)
{
	if (character >= 'A' && character <= 'Z')
		return (character + 32);
	return (character);
}
