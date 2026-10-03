/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:19:26 by sbanimou          #+#    #+#             */
/*   Updated: 2026/10/03 10:13:41 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_disorder(t_parsed *parsed)
{
	size_t	index;
	size_t	next_index;
	int		mistakes;
	int		total_pairs;

	index = 0;
	mistakes = 0;
	total_pairs = 0;
	while (index < parsed->sequence_size)
	{
		next_index = index + 1;
		while (next_index < parsed->sequence_size)
		{
			total_pairs++;
			if (parsed->sequence[index] > parsed->sequence[next_index])
				mistakes++;
			next_index++;
		}
		index++;
	}
	if (total_pairs == 0)
		parsed->disorder = 0.0;
	else
		parsed->disorder = (double)mistakes / total_pairs;
	return (1);
}
