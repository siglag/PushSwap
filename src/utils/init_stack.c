/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:19:52 by sbanimou          #+#    #+#             */
/*   Updated: 2026/10/03 15:24:52 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// copy element from the seq into the stack a
t_stack	*init_stack(t_parsed *parsed)
{
	t_stack	*stack;
	size_t	i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = malloc(sizeof(int) * parsed->sequence_size);
	stack->b = malloc(sizeof(int) * parsed->sequence_size);
	if (!stack->a || !stack->b)
		return (free(stack), NULL);
	i = 0;
	while (i < parsed->sequence_size)
	{
		stack->a[i] = parsed->sequence[i];
		i++;
	}
	stack->size_a = (int)parsed->sequence_size;
	stack->size_b = 0;
	stack->parsed = parsed;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	free(stack);
}
