/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 10:35:07 by sbanimou          #+#    #+#             */
/*   Updated: 2026/10/04 17:26:40 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push_current_chunk(t_stack *stack, int start, int end)
{
	int	moved;
	int	half;

	moved = 0;
	half = (end - start) / 2;
	while (moved < end - start)
	{
		if (stack->a[0] >= start && stack->a[0] < end)
		{
			pb(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
			if (stack->b[0] < start + half)
				rb(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
			moved++;
		}
		else
			ra(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	}
}

static void	push_chunks_to_b(t_stack *stack, int chunk_size)
{
	int	start;
	int	end;

	start = 0;
	while (start < stack->size_a)
	{
		end = start + chunk_size;
		if (end > stack->size_a)
			end = stack->size_a;
		push_current_chunk(stack, start, end);
		start = end;
	}
}

static int	find_max_index_pos(t_stack *stack)
{
	int	index;
	int	max_index;
	int	max_pos;

	index = 0;
	max_index = -1;
	max_pos = 0;
	while (index < stack->size_b)
	{
		if (stack->b[index] > max_index)
		{
			max_index = stack->b[index];
			max_pos = index;
		}
		index++;
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
				rb(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
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
	chunk_size = 1;
	while (chunk_size * chunk_size < stack->size_a)
		chunk_size++;
	push_chunks_to_b(stack, chunk_size);
	push_back_to_a(stack);
	return (1);
}