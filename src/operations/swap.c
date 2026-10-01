/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbanimou <sbanimou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 09:34:05 by sbanimou          #+#    #+#             */
/*   Updated: 2026/09/29 13:37:24 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// arr[0] Top of stack
static void	swap_array(int *arr, int size)
{
	int	tmp;

	if (!arr || size < 2)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
}

// Swap the first two elements at the top of stack a
void	sa(t_stack *stack)
{
	if (!stack)
		return ;
	swap_array(stack->a, stack->size_a);
}

// Swap the first two elements at the top of stack b
void	sb(t_stack *stack)
{
	if (!stack)
		return ;
	swap_array(stack->b, stack->size_b);
}

// sa and sb at the same time
void	ss(t_stack *stack)
{
	if (!stack)
		return ;
	swap_array(stack->a, stack->size_a);
	swap_array(stack->b, stack->size_b);
}
