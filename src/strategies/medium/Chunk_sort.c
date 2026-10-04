/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 10:35:07 by sbanimou          #+#    #+#             */
/*   Updated: 2026/10/04 17:15:34 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//((Medium)) handles medium stacks using chunk-based sorting
static int	get_chunk_size(int n)
{
	int	size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}

static void	push_chunks_to_b(t_stack *stack, int chunk_size)
{
	int	current_max;

	current_max = chunk_size;
	while (stack->size_a > 0)
	{
		if (stack->a[0] < current_max)
		{
			pb(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
			if (stack->size_b > 1
				&& stack->b[0] < current_max - (chunk_size / 2))
				rb(stack, stack->parsed->is_bench,
					!stack->parsed->is_bench);
			if (current_max < stack->size_a + stack->size_b)
				current_max++;
		}
		else
			ra(stack, stack->parsed->is_bench,
				!stack->parsed->is_bench);
	}
}

static int	find_max_index_pos(t_stack *stack)
{
	int	i;
	int	max_idx;
	int	max_pos;

	i = 0;
	max_idx = -1;
	max_pos = 0;
	while (i < stack->size_b)
	{
		if (stack->b[i] > max_idx)
		{
			max_idx = stack->b[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

static void	push_back_to_a(t_stack *stack)
{
	int	max_pos;
	int	steps;

	while (stack->size_b > 0)
	{
		max_pos = find_max_index_pos(stack);
		if (max_pos <= stack->size_b / 2)
		{
			steps = max_pos;
			while (steps-- > 0)
				rb(stack, stack->parsed->is_bench,
					!stack->parsed->is_bench);
		}
		else
		{
			steps = stack->size_b - max_pos;
			while (steps-- > 0)
				rrb(stack, stack->parsed->is_bench,
					!stack->parsed->is_bench);
		}
		pa(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	}
}

int	medium_strategy(t_stack *stack)
{
	int	chunk_size;

	if (!stack)
		return (0);
	if (is_sorted(stack))
		return (1);
	index_stack(stack);
	chunk_size = get_chunk_size(stack->size_a);
	push_chunks_to_b(stack, chunk_size);
	push_back_to_a(stack);
	return (1);
}
