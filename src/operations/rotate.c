/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:46:49 by sbanimou          #+#    #+#             */
/*   Updated: 2026/09/29 16:42:45 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// The first element becomes the last in stack a
void	ra(t_stack *stack)
{
	int	first;
	int	i;

	if (!stack || stack->size_a < 2)
		return ;
	first = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = first;
	if (stack->parsed && stack->parsed->operations)
                stack->parsed->operations->ra++;
        write(1, "ra\n", 3);
}

// The first element becomes the last in stack b
void	rb(t_stack *stack)
{
	int	first;
	int	i;

	if (!stack || stack->size_b < 2)
		return ;
	first = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = first;

	if (stack->parsed && stack->parsed->operations)
                stack->parsed->operations->rb++;
        write(1, "rb\n", 3);
}
//i am gonna change it
// ra and rb at the same time
void	rr(t_stack *stack)
{
	if (!stack)
		return ;
	ra(stack);
	rb(stack);
}
