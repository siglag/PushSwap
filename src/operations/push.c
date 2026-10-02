/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:42:05 by sbanimou          #+#    #+#             */
/*   Updated: 2026/09/29 14:46:14 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//Take the first element at the top of b and put it at the top of a
void	pa(t_stack *stack)
{
	int	i;

	if (!stack || stack->size_b == 0)
		return ;
	i = stack->size_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->size_a++;
	stack->size_b--;

	if (stack->parsed && stack->parsed->operations)
                stack->parsed->operations->pa++;
        write(1, "pa\n", 3);
}

//Take the first element at the top of a and put it at the top of b
void	pb(t_stack *stack)
{
	int	i;

	if (!stack || stack->size_a == 0)
		return ;
	i = stack->size_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->size_b++;
	stack->size_a--;

	if (stack->parsed && stack->parsed->operations)
                stack->parsed->operations->pb++;
        write(1, "pb\n", 3);
}
