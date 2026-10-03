/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Redix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 16:35:22 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/03 16:35:52 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	helper(t_stack *stack, size_t bit)
{
	if (((stack->a[0] >> bit) & 1) == 0)
		pb(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	else
		ra(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	return (1);
}

int	complex_strategy(t_stack *stack)
{
	size_t	bit;
	size_t	index;
	size_t	size;
	size_t	max_bits;

	bit = 0;
	max_bits = 0;
	size = stack->size_a;
	while ((size - 1) >> max_bits)
		max_bits++;
	while (bit < max_bits)
	{
		index = 0;
		while (index < size)
		{
			helper(stack, bit);
			index++;
		}
		while (stack->size_b > 0)
			pa(stack, stack->parsed->is_bench,
				!stack->parsed->is_bench);
		bit++;
	}
	return (1);
}
