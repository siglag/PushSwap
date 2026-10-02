/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:52:47 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/02 15:30:41 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_strategy(t_parsed *parsed)
{
	if (!parsed)
		return (0);
	if (parsed->strategy == ADAPTIVE)
	{
		if (parsed->disorder < 0.2)
			parsed->strategy = SIMPLE;
		else if (parsed->disorder < 0.5)
			parsed->strategy = MEDIUM;
		else
			parsed->strategy = COMPLEX;
	}
	return (1);
}

int	strategies_router(t_parsed *parsed)
{
	t_stack	*stack;

	if (!parsed)
		return (0);
	stack = init_stack(parsed);
	if (!stack || !choose_strategy(parsed))
		return (0);
	if (parsed->strategy == SIMPLE)
		return (simple_strategy(stack));
	else if (parsed->strategy == MEDIUM)
		return (medium_strategy(stack));
	else if (parsed->strategy == COMPLEX)
		return (complex_strategy(stack));
	else
		return (0);
}
