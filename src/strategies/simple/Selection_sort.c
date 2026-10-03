/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 09:22:32 by sbanimou          #+#    #+#             */
/*   Updated: 2026/10/03 12:14:33 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//((Simple))handles small stacks: 2 to 5 elements
static bool	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->size_a < 2)
		return (true);
	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

static int	get_min_index(t_stack *stack)
{
	int	min_idx;
	int	i;

	min_idx = 0;
	i = 1;
	while (i < stack->size_a)
	{
		if (stack->a[i] < stack->a[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

static void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->size_a != 3)
		return ;
	a = stack->a[0];
	b = stack->a[1];
	c = stack->a[2];
	if (a > b && b < c && a < c)
		sa(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	else if (a > b && b > c)
	{
		sa(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
		rra(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	}
	else if (a > b && b < c && a > c)
		ra(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	else if (a < b && b > c && a < c)
	{
		sa(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
		ra(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	}
	else if (a < b && b > c && a > c)
		rra(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
}

static void	push_min_to_b(t_stack *stack)
{
	int	min_idx;
	int	steps;

	min_idx = get_min_index(stack);
	if (min_idx <= stack->size_a / 2)
	{
		while (min_idx-- > 0)
			ra(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	}
	else
	{
		steps = stack->size_a - min_idx;
		while (steps-- > 0)
			rra(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	}
	pb(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
}

int	simple_strategy(t_stack *stack)
{
	if (!stack)
		return (0);
	if (is_sorted(stack))
		return (1);
	if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
		return (1);
	}
	while (stack->size_a > 3)
		push_min_to_b(stack);
	if (!is_sorted(stack))
		sort_three(stack);
	while (stack->size_b > 0)
		pa(stack, stack->parsed->is_bench, !stack->parsed->is_bench);
	return (1);
}
