/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:52:47 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/01 16:34:32 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int strategies_router(t_parsed *parsed)
{
	t_stack	*stack;

	if (!parsed)
		return (-1);
	stack = init_stack(parsed);
	if (parsed->strategy == SIMPLE)
		return (simple_strategy(stack));
	else if (parsed->strategy == MEDIUM)
		return (medium_strategy(stack));
	else if (parsed->strategy == COMPLEX)
		return (complex_strategy(stack));
	else
		return (-1);
}