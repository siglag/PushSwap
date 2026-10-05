/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:49:07 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/03 23:56:02 by mohammah         ###   ########.fr       */
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
		if (*str++ == '-')
			sign = -1;
	}
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str++ - '0');
		if ((sign == 1 && number > INT_MAX)
			|| (sign == -1 && number > 2147483648L))
			return (0);
	}
	if (*str)
		return (0);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;
	char			*res;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
