/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:49:07 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/30 08:45:00 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

/*
	count numbers sperated by whitespaces
*/
int	count_numbers(char *str)
{
	int	count;
	int	in_number;
	int	index;

	count = 0;
	in_number = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
		{
			if (!in_number)
			{
				in_number = 1;
				count++;
			}
		}
		else
			in_number = 0;
		index++;
	}
	return (count);
}
