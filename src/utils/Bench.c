/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:15:56 by sbanimou          #+#    #+#             */
/*   Updated: 2026/10/03 23:38:23 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*bench_strategy(t_parsed *parsed)
{
	if (parsed->strategy == SIMPLE)
		return ("O(n2)");
	else if (parsed->strategy == MEDIUM)
		return ("O(n√n)");
	else if (parsed->strategy == COMPLEX)
		return ("O(n log n)");
	else
		return ("NULL");
}

int	count_operations(t_parsed *parsed)
{
	parsed->operations.total += parsed->operations.pa;
	parsed->operations.total += parsed->operations.pb;
	parsed->operations.total += parsed->operations.ra;
	parsed->operations.total += parsed->operations.rb;
	parsed->operations.total += parsed->operations.rr;
	parsed->operations.total += parsed->operations.rra;
	parsed->operations.total += parsed->operations.rrb;
	parsed->operations.total += parsed->operations.rrr;
	parsed->operations.total += parsed->operations.sa;
	parsed->operations.total += parsed->operations.sb;
	parsed->operations.total += parsed->operations.ss;
	return (parsed->operations.total);
}

char	*strategy_name(t_parsed *parsed)
{
	if (parsed->adaptive == true)
		return ("Adaptive");
	else if (parsed->strategy == SIMPLE)
		return ("Simple");
	else if (parsed->strategy == MEDIUM)
		return ("Medium");
	else if (parsed->strategy == COMPLEX)
		return ("Complex");
	else
		return ("Unknown");
}

int	bench(t_parsed *parsed)
{
	if (!parsed->is_bench)
		return (0);
	ft_printf(2, "[bench] disorder: %s%%\n", ft_dtoa(parsed->disorder * 100, 2));
	ft_printf(2, "[bench] strategy: %s / %s\n",
		strategy_name(parsed),
		bench_strategy(parsed));
	ft_printf(2, "[bench] total_ops: %d\n", count_operations(parsed));
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d  ",
		parsed->operations.sa,
		parsed->operations.sb,
		parsed->operations.ss);
	ft_printf(2, "pa: %d  pb: %d\n", parsed->operations.pa, parsed->operations.pb);
	ft_printf(2, "[bench] ra: %d  rb: %d  rr: %d  ",
		parsed->operations.ra,
		parsed->operations.rb,
		parsed->operations.rr);
	ft_printf(2, "rra: %d  rrb: %d  rrr: %d\n",
		parsed->operations.rra,
		parsed->operations.rrb,
		parsed->operations.rrr);
	return (1);
}
