/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:49:07 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/02 13:57:34 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int *result)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		if (sign == 1 && number > 2147483647)
			return (0);
		if (sign == -1 && number > 2147483648)
			return (0);
		str++;
	}
	*result = (int)(number * sign);
	return (1);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	index = 0;
	while (index < len)
	{
		sub[index] = s[start + index];
		index++;
	}
	sub[index] = '\0';
	return (sub);
}
