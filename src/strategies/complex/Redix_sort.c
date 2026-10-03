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

static void	sort_bit(t_stack *stack, size_t bit)
{
	size_t	index;
	size_t	size;

	index = 0;
	size = stack->size_a;
	while (index < size)
	{
		if (((stack->a[0] >> bit) & 1) == 0)
			pb(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
		else
			ra(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
		index++;
	}
	while (stack->size_b > 0)
		pa(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
}

int	complex_strategy(t_stack *stack)
{
	size_t	bit;
	size_t	max_bits;

	if (!stack || stack->size_a < 2)
		return (1);
	index_stack(stack);
	max_bits = 0;
	while ((stack->size_a - 1) >> max_bits)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(stack, bit);
		bit++;
	}
	return (1);
}
