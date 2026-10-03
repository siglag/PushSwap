/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:44:55 by sbanimou          #+#    #+#             */
/*   Updated: 2026/10/03 12:50:08 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < stack->size_a)
	{
		count = 0;
		j = 0;
		while (j < stack->size_a)
		{
			if (stack->a[j] < stack->a[i])
				count++;
			j++;
		}
		stack->index_a[i] = count;
		i++;
	}
}
