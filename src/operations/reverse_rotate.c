/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:31:35 by sbanimou          #+#    #+#             */
/*   Updated: 2026/09/29 17:04:08 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// The last element becomes the first in stack a
void	rra(t_stack *stack, bool print_and_count) 
{
	int	last;
	int	i;

	if (!stack || stack->size_a < 2)
		return ;
	last = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = last;
	 if (print_and_count)
        {
                if (stack->parsed && stack->parsed->operations)
                        stack->parsed->operations->rra++;
                write(1, "rra\n", 4);
        }
}

// The last element becomes the first in stack b
void	rrb(t_stack *stack, bool print_and_count)
{
	int	last;
	int	i;

	if (!stack || stack->size_b < 2)
		return ;
	last = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = last;
	 if (print_and_count)
        {
                if (stack->parsed && stack->parsed->operations)
                        stack->parsed->operations->rrb++;
                write(1, "rrb\n", 4);
        }
}

// rra and rrb at the same time
void	rrr(t_stack *stack)
{
	if (!stack || (stack->size_a < 2 && stack->size_b < 2)) 
		return ;
	rra(stack, false);
	rrb(stack, false);
	if (stack->parsed && stack->parsed->operations)
		stack->parsed->operations->rrr++;
	write(1, "rrr\n", 4);

}
