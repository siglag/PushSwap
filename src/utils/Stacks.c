/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:44:55 by sbanimou          #+#    #+#             */
/*   Updated: 2026/10/03 14:34:59 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	index_stack(t_stack *stack)
{
	int	*temp;
	int	i;
	int	j;
	int	count;

	if (!stack || stack->size_a <= 0)
		return (0);
	temp = malloc(sizeof(int) * stack->size_a);
	if (!temp)
		return (0);
	i = -1;
	while (++i < stack->size_a)
	{
		count = 0;
		j = -1;
		while (++j < stack->size_a)
			if (stack->a[j] < stack->a[i])
				count++;
		temp[i] = count;
	}
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = temp[i];
	free(temp);
	return (1);
}

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
		return (free(stack->a), free(stack->b), free(stack), NULL);
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
