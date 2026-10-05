/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:52:47 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/03 10:19:04 by sbanimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_strategy(t_parsed *parsed)
{
	if (!parsed)
		return (0);
	if (parsed->strategy == ADAPTIVE)
	{
		if (parsed->sequence_size <= 5)
			parsed->strategy = SIMPLE;
		else if (parsed->disorder < 0.2)
			parsed->strategy = SIMPLE;
		else if (parsed->disorder < 0.5)
			parsed->strategy = MEDIUM;
		else
			parsed->strategy = COMPLEX;
	}
	return (1);
}

// to avoid memory leak
int	strategies_router(t_parsed *parsed)
{
	t_stack	*stack;
	int		result;

	if (!parsed)
		return (0);
	stack = init_stack(parsed);
	if (!stack)
		return (0);
	if (!choose_strategy(parsed))
	{
		free_stack(stack);
		return (0);
	}
	if (parsed->strategy == SIMPLE)
		result = (simple_strategy(stack));
	else if (parsed->strategy == MEDIUM)
		result = (medium_strategy(stack));
	else if (parsed->strategy == COMPLEX)
		result = (complex_strategy(stack));
	else
		result = 0;
	free_stack(stack);
	return (result);
}
