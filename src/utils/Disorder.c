/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:19:26 by sbanimou          #+#    #+#             */
/*   Updated: 2026/10/01 19:05:46 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

double	calculate_disorder(t_parsed *parsed)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < parsed->sequence_size)
	{
		j = i + 1;
		while (j < parsed->sequence_size)
		{
			total_pairs++;
			if (parsed->sequence[i] > parsed->sequence[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}

void	choose_strategy(t_parsed *parsed)
{
	if (parsed->disorder < 0.2)
		parsed->strategy = SIMPLE;
	else if (parsed->disorder < 0.5)
		parsed->strategy = MEDIUM;
	else
		parsed->strategy = COMPLEX;
}
